/*
http://docs.huihoo.com/doxygen/linux/kernel/3.7/include_2linux_2can_2dev_8h_source.html
참고링크
*/
/* Xilinx CAN device driver
 *
 * Copyright (C) 2012 - 2014 Xilinx, Inc.
 * Copyright (C) 2009 PetaLogix. All rights reserved.
 *
 * Description:
 * This driver is developed for Axi CAN IP and for Zynq CANPS Controller.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
/*
 * Analysing Goal 2017-06-15 ~ 2017-06-16
 * Writing Rule :
 *  writer
 *  Meaning of this code
 *  Comment
 */
 
#include <linux/clk.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/io.h>   //  I/O 처리기법에서 사용
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/skbuff.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/can/dev.h>
#include <linux/can/error.h>
#include <linux/can/led.h>
#include <linux/pm_runtime.h>
 
#define DRIVER_NAME    "xilinx_can"
 
/*
 * 전슬기
 * CAN 컨트롤러에서 사용하는 모든 레지스터들에 대한 것으로 그 각 레지스터의 시작 위치 상수 값들.
 * ug585 B.5 CAN Controller 참조
 */
/* CAN registers set */
enum xcan_reg {
    XCAN_SRR_OFFSET   	 = 0x00, /* Software reset */
    XCAN_MSR_OFFSET   	 = 0x04, /* Mode select */
    XCAN_BRPR_OFFSET    = 0x08, /* Baud rate prescaler */
    XCAN_BTR_OFFSET   	 = 0x0C, /* Bit timing */
    XCAN_ECR_OFFSET   	 = 0x10, /* Error counter */
    XCAN_ESR_OFFSET   	 = 0x14, /* Error status */
    XCAN_SR_OFFSET   	 = 0x18, /* Status */
    XCAN_ISR_OFFSET   	 = 0x1C, /* Interrupt status */
    XCAN_IER_OFFSET   	 = 0x20, /* Interrupt enable */
    XCAN_ICR_OFFSET   	 = 0x24, /* Interrupt clear */
    XCAN_TXFIFO_ID_OFFSET    = 0x30,/* TX FIFO ID */
    XCAN_TXFIFO_DLC_OFFSET    = 0x34, /* TX FIFO DLC */
    XCAN_TXFIFO_DW1_OFFSET    = 0x38, /* TX FIFO Data Word 1 */
    XCAN_TXFIFO_DW2_OFFSET    = 0x3C, /* TX FIFO Data Word 2 */
    XCAN_RXFIFO_ID_OFFSET    = 0x50, /* RX FIFO ID */
    XCAN_RXFIFO_DLC_OFFSET    = 0x54, /* RX FIFO DLC */
    XCAN_RXFIFO_DW1_OFFSET    = 0x58, /* RX FIFO Data Word 1 */
    XCAN_RXFIFO_DW2_OFFSET    = 0x5C, /* RX FIFO Data Word 2 */
};
 
 
/*
 * 전슬기
 * CAN 컨트롤러에서 사용하는 모든 레지스터들의 Bit 마스크
 * ug585 B.5 CAN Controller 참조
 */
/* CAN register bit masks - XCAN_<REG>_<BIT>_MASK */
#define XCAN_SRR_CEN_MASK   	 0x00000002 /* CAN enable */
#define XCAN_SRR_RESET_MASK   	 0x00000001 /* Soft Reset the CAN core */
#define XCAN_MSR_LBACK_MASK   	 0x00000002 /* Loop back mode select */
#define XCAN_MSR_SLEEP_MASK   	 0x00000001 /* Sleep mode select */
#define XCAN_BRPR_BRP_MASK   	 0x000000FF /* Baud rate prescaler */
#define XCAN_BTR_SJW_MASK   	 0x00000180 /* Synchronous jump width */
#define XCAN_BTR_TS2_MASK   	 0x00000070 /* Time segment 2 */
#define XCAN_BTR_TS1_MASK   	 0x0000000F /* Time segment 1 */
#define XCAN_ECR_REC_MASK   	 0x0000FF00 /* Receive error counter */
#define XCAN_ECR_TEC_MASK   	 0x000000FF /* Transmit error counter */
#define XCAN_ESR_ACKER_MASK   	 0x00000010 /* ACK error */
#define XCAN_ESR_BERR_MASK   	 0x00000008 /* Bit error */
#define XCAN_ESR_STER_MASK   	 0x00000004 /* Stuff error */
#define XCAN_ESR_FMER_MASK   	 0x00000002 /* Form error */
#define XCAN_ESR_CRCER_MASK   	 0x00000001 /* CRC error */
#define XCAN_SR_TXFLL_MASK   	 0x00000400 /* TX FIFO is full */
#define XCAN_SR_ESTAT_MASK   	 0x00000180 /* Error status */
#define XCAN_SR_ERRWRN_MASK   	 0x00000040 /* Error warning */
#define XCAN_SR_NORMAL_MASK   	 0x00000008 /* Normal mode */
#define XCAN_SR_LBACK_MASK   	 0x00000002 /* Loop back mode */
#define XCAN_SR_CONFIG_MASK   	 0x00000001 /* Configuration mode */
#define XCAN_IXR_TXFEMP_MASK   	 0x00004000 /* TX FIFO Empty */
#define XCAN_IXR_WKUP_MASK   	 0x00000800 /* Wake up interrupt */
#define XCAN_IXR_SLP_MASK   	 0x00000400 /* Sleep interrupt */
#define XCAN_IXR_BSOFF_MASK   	 0x00000200 /* Bus off interrupt */
#define XCAN_IXR_ERROR_MASK   	 0x00000100 /* Error interrupt */
#define XCAN_IXR_RXNEMP_MASK   	 0x00000080 /* RX FIFO NotEmpty intr */
#define XCAN_IXR_RXOFLW_MASK   	 0x00000040 /* RX FIFO Overflow intr */
#define XCAN_IXR_RXOK_MASK   	 0x00000010 /* Message received intr */
#define XCAN_IXR_TXFLL_MASK   	 0x00000004 /* Tx FIFO Full intr */
#define XCAN_IXR_TXOK_MASK   	 0x00000002 /* TX successful intr */
#define XCAN_IXR_ARBLST_MASK   	 0x00000001 /* Arbitration lost intr */
#define XCAN_IDR_ID1_MASK   	 0xFFE00000 /* Standard msg identifier */
#define XCAN_IDR_SRR_MASK   	 0x00100000 /* Substitute remote TXreq */
#define XCAN_IDR_IDE_MASK   	 0x00080000 /* Identifier extension */
#define XCAN_IDR_ID2_MASK   	 0x0007FFFE /* Extended message ident */
#define XCAN_IDR_RTR_MASK   	 0x00000001 /* Remote TX request */
#define XCAN_DLCR_DLC_MASK   	 0xF0000000 /* Data length code */
 
 
/*
 * 전슬기
 * 매크로 함수로서 특정 인터럽트 비트가 활성화 되어 있을 경우 true를 반환한다.
 * 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) ISR 참조
 */
#define XCAN_INTR_ALL   	 (XCAN_IXR_TXOK_MASK | XCAN_IXR_BSOFF_MASK |\
   			  XCAN_IXR_WKUP_MASK | XCAN_IXR_SLP_MASK | \
   			  XCAN_IXR_RXNEMP_MASK | XCAN_IXR_ERROR_MASK | \
   			  XCAN_IXR_RXOFLW_MASK | \
   			  XCAN_IXR_ARBLST_MASK)
 
 
/* CAN register bit shift - XCAN_<REG>_<BIT>_SHIFT */
/*
 * 전슬기
 * CAN 컨트롤러에서 사용하는 레지스터들에 대한 것으로 그 레지스터의 시작 bit 값.
 * 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) BTR 참조
 */
#define XCAN_BTR_SJW_SHIFT   	 7  /* Synchronous jump width */
#define XCAN_BTR_TS2_SHIFT   	 4  /* Time segment 2 */
 
/*
 * 전슬기
 * CAN 컨트롤러에서 사용하는 레지스터들에 대한 것으로 그 레지스터의 시작 bit 값.
 * 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) TXFIFO_ID 참조
 */
#define XCAN_IDR_ID1_SHIFT   	 21 /* Standard Messg Identifier */
#define XCAN_IDR_ID2_SHIFT   	 1  /* Extended Message Identifier */
 
/*
 * 전슬기
 * CAN 컨트롤러에서 사용하는 레지스터들에 대한 것으로 그 레지스터의 시작 bit 값.
 * 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) TXHPB_DLC참조
 */
#define XCAN_DLCR_DLC_SHIFT   	 28 /* Data length code */
 
/*
 * 전슬기
  * CAN 컨트롤러에서 사용하는 레지스터들에 대한 것으로 8번 bit 자리는 예약된 값.
 * 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) TXHPB_DLC참조
 */
#define XCAN_ESR_REC_SHIFT   	 8  /* Rx Error Count */
 
/* CAN frame length constants */
/*
 * 전슬기
 * CAN 프레임의 제어 필드의 데이터 길이.
 * 자세한 사항은 ug585 B.5 CAN Controller에 DLC Word(p.564) 참조
 */
#define XCAN_FRAME_MAX_DATA_LEN   	 8
 
#define XCAN_TIMEOUT   		 (1 * HZ)
 
 /**
 * ADS
 * struct xcan_priv - This definition define CAN driver instance
   이 정의는 CAN 드라이버 인스턴스를 정의합니다.
 * @can:			CAN private data structure.
				CAN 개인 데이터 구조.
 * @tx_head:			Tx CAN packets ready to send on the queue
				대기열에서 보낼 준비가 된 Tx CAN 패킷
 * @tx_tail:			Tx CAN packets successfully sended on the queue
				Tx CAN 패킷이 대기열에서 성공적으로 발송되었습니다.
 
 * @tx_max:			Maximum number packets the driver can send
				드라이버가 보낼 수있는 최대 패킷 수
 * @napi:			NAPI structure
				NAPI 구조
 * @read_reg:			For reading data from CAN registers
				CAN 레지스터로부터 데이터 읽기
 * @write_reg:			For writing data to CAN registers
				CAN 레지스터에 데이터 쓰기
 * @dev:			Network device data structure
				네트워크 장치 데이터 구조
 * @reg_base:			Ioremapped address to registers
				주소에 매핑 된 주소
 * @irq_flags:			For request_irq()
				request_irq ()에 대해
 * @bus_clk:			Pointer to struct clk
				struct clk에 대한 포인터
 * @can_clk:			Pointer to struct clk
				struct clk에 대한 포인터
 */
 
struct xcan_priv {
    struct can_priv can; // ADS : dev.h 에 선언 CAN common private data
    unsigned int tx_head;
    unsigned int tx_tail;
    unsigned int tx_max;
/*
napi_struct -> ADS : Netdevice.h 에 정의
Structure for NAPI scheduling similar to tasklet but with weighting 
태스크 릿과 비슷하지만 가중치가있는 NAPI 스케줄링을위한 구조
 
poll_list는 NAPI_STATE_SCHED 비트의 상태를 변경하는 엔티티에 의해서만 관리되어야합니다. 이것은 누구든지 원자적으로 그 비트를 설정하면 이 napi_struct를 CPU 당 poll_list에 추가 할 수 있으며, 비트를 지우면 누구도 비트를 지우기 전에 목록에서 제거 할 수 있습니다.
*/ 
    struct napi_struct napi; 
    u32 (*read_reg)(const struct xcan_priv *priv, enum xcan_reg reg);
    void (*write_reg)(const struct xcan_priv *priv, enum xcan_reg reg,
   		 u32 val);
    struct device *dev; // ADS : Device.h 에 정의. 정의부에 굉장한 주석이 있음. 추후 쓸때 참고
 
    void __iomem *reg_base;
    unsigned long irq_flags;
    struct clk *bus_clk;
    struct clk *can_clk;
};
 
/* 
CAN Bittiming constants as per Xilinx CAN specs 
Xilinx CAN 사양에 따른 CAN 비트 타이밍 (bittiming) 상수
 */
static const struct can_bittiming_const xcan_bittiming_const = {
    .name = DRIVER_NAME,
    .tseg1_min = 1,
    .tseg1_max = 16,
    .tseg2_min = 1,
    .tseg2_max = 8,
    .sjw_max = 4,
    .brp_min = 1,
    .brp_max = 256,
    .brp_inc = 1,
};
 
/*
* 전슬기
 * xcan_write_reg_le - Write a value to the device register little endian   	
하위 바이트의 값이 메모리에 먼저 표시되는 방법(little Endian)으로 값 쓰기
 * endian 이란??  	
파일시스템 데이터를 관리하는 방법 중 하나, 주로 character드라이버에서 사용
 * @priv:    Driver private data structure
 * @reg:    Register offset
 * @val:    Value to write at the Register offset
 *
 * Write data to the paricular CAN register
 */
static void xcan_write_reg_le(const struct xcan_priv *priv, enum xcan_reg reg,
   		 u32 val)
{
    iowrite32(val, priv->reg_base + reg);   	
//레지스터에 매핑된 주소(reg_base)에서 레지스터 옵셋(reg)을 더한 곳에 값을(value)기입
}
 
/**
 * xcan_read_reg_le - Read a value from the device register little endian   	
하위 바이트의 값이 메모리에 먼저 표시되는 방법(little Endian)으로 값 읽기
 * @priv:    Driver private data structure
 * @reg:    Register offset
 *
 * Read data from the particular CAN register
 * Return: value read from the CAN register
 */
static u32 xcan_read_reg_le(const struct xcan_priv *priv, enum xcan_reg reg)
{
    return ioread32(priv->reg_base + reg);  	
 //레지스터에 매핑된 주소(reg_base)에서 레지스터 옵셋(reg)을 더한 곳을 읽기
}
 
/**
 * xcan_write_reg_be - Write a value to the device register big endian 	
상위 바이트의 값이 메모리에 먼저 표시되는 방법(big Endian)으로 값 쓰기
 * @priv:    Driver private data structure
 * @reg:    Register offset
 * @val:    Value to write at the Register offset
 *
 * Write data to the paricular CAN register
 */
static void xcan_write_reg_be(const struct xcan_priv *priv, enum xcan_reg reg,
   		 u32 val)
{
    iowrite32be(val, priv->reg_base + reg); 	
//레지스터에 매핑된 주소(reg_base)에서 레지스터 옵셋(reg)을 더한 곳에 값을(value)기입
}
 
/**
 * xcan_read_reg_be - Read a value from the device register big endian  	
상위 바이트의 값이 메모리에 먼저 표시되는 방법(big Endian)으로 값 읽기
 * @priv:    Driver private data structure
 * @reg:    Register offset
 *
 * Read data from the particular CAN register
 * Return: value read from the CAN register
 */
static u32 xcan_read_reg_be(const struct xcan_priv *priv, enum xcan_reg reg)
{
    return ioread32be(priv->reg_base + reg);	
//레지스터에 매핑된 주소(reg_base)에서 레지스터 옵셋(reg)을 더한 곳을 읽기
}
 
/**
 * set_reset_mode - Resets the CAN device mode  can디바이스 모드를 리셋
 * @ndev:    Pointer to net_device structure
 *
 * This is the driver reset mode routine.The driver
 * enters into configuration mode.
 *
 * Return: 0 on success and failure value on error
 */
static int set_reset_mode(struct net_device *ndev)
{
    struct xcan_priv *priv = netdev_priv(ndev);
   // Netdevice.h 에 정의. netdev_priv : 네트워크 장치 개인 데이터 가져 오기
    unsigned long timeout;
 
    	priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);	
// CAN레지스터(XCAN_SRR_OFFSET)에 데이터(XCAN_SRR_RESET_MASK)를 쓴다.
 
    timeout = jiffies + XCAN_TIMEOUT; 
// jiffies이란? 시스템 내의 전역적인 변수로써 초당 HZ값 만큼 숫자가 증가하게 된다.
// timeout = gettimeofday에서 가져온 값 + (1 * Hz)
    while (!(priv->read_reg(priv, XCAN_SR_OFFSET) & XCAN_SR_CONFIG_MASK)) { 	
// CAN레지스터(XCAN_SR_OFFSET)에 데이터를 읽는것 
// CAN컨트롤러가 구성에 있다(XCAN_SR_CONFIG_MASK)
// ADS : 레지스터에서 읽은 값(XCAN_SR_OFFSET)과 
// XCAN_SR_CONFIG_MASK (설정모드)를 & 연산. 
   	 if (time_after(jiffies, timeout)) { 	//jiffies가 timeout보다 크면 true를 반환
   		 netdev_warn(ndev, "timed out for config mode\n");   	
                      // 구성모드에 대해 시간 초과됨
   		 return -ETIMEDOUT;  	// 접속 타임 아웃
   	 }
   	 usleep_range(500, 10000);   
 	// 수면시간 범위 : 수면시간 최소값 500, 수면시간 최대값 10000
    }
 
    return 0;
} // -> 즉, 타임아웃 값을 설정하고 레지스터의 값을 읽어 성공하면 수면상태에 빠진다(?)
 
/**
 * xcan_set_bittiming - CAN set bit timing routine
 * @ndev:    Pointer to net_device structure
 *
 * This is the driver set bittiming  routine. 드라이버가 bittiming 루틴을 설정합니다
 * Return: 0 on success and failure value on error
 */
static int xcan_set_bittiming(struct net_device *ndev)
{
    struct xcan_priv *priv = netdev_priv(ndev);
    struct can_bittiming *bt = &priv->can.bittiming;	
     // CAN데이터구조체에 Bit Timing 값. 
/* ADS
   can_bittiming 구조체 
    	__u32 bitrate;		/* Bit-rate in bits/second */
				   비트 / 초 단위의 비트 전송률
	__u32 sample_point;	/* Sample point in one-tenth of a percent */
				   1 / 10 %의 샘플 포인트
	__u32 tq;		/* Time quanta (TQ) in nanoseconds */
				    시간 간격 (TQ) (나노초 단위)
	__u32 prop_seg;	/* Propagation segment in TQs */
				   TQ의 전파 부분
	__u32 phase_seg1;	/* Phase buffer segment 1 in TQs */
				   TQ의 위상 버퍼 세그먼트 1
	__u32 phase_seg2;	/* Phase buffer segment 2 in TQs */
				   TQ의 위상 버퍼 세그먼트 2
	__u32 sjw;		/* Synchronisation jump width in TQs */
				   TQ의 동기화 점프 폭
	__u32 brp;		/* Bit-rate prescaler */
*/ 
    u32 btr0, btr1;
    u32 is_config_mode;
 
    /* 
       Check whether Xilinx CAN is in configuration mode.
        Xilinx CAN이 구성 모드에 있는지 확인하십시오.
     * It cannot set bit timing if Xilinx CAN is not in configuration mode.
       Xilinx CAN이 구성 모드에 있지 않으면 비트 타이밍을 설정할 수 없습니다.
     */
    is_config_mode = priv->read_reg(priv, XCAN_SR_OFFSET) &
   			 XCAN_SR_CONFIG_MASK;    	
// CAN레지스터(XCAN_SR_OFFSET)에 데이터를 읽는것 & 
// CAN컨트롤러가 구성에 있다(XCAN_SR_CONFIG_MASK)
// 구성모드 설정
    if (!is_config_mode) {  // 구성준비가 되지 않았다면
   	 netdev_alert(ndev,
   	  	"BUG! Cannot set bittiming - CAN is not in config mode\n");	
    // 구성 모드에 있지 않다면 CAN Bit Timing 을 설정할 수 없다.
   	 return -EPERM;  	// EPERM : 작동이 허용되지 않는다.
    }
 
  /* Setting Baud Rate prescalar value in BRPR Register */
    btr0 = (bt->brp - 1);    	
    // 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) BRPR 참조
    // brp : Bit-rate prescaler
 
    /* Setting Time Segment 1 in BTR Register */
    btr1 = (bt->prop_seg + bt->phase_seg1 - 1);     	
   // 표준 지정된 전파세그먼트와 위상 세그먼트1의 합계를 나타낸다.
   // 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) BTR에 TS1참조
 
    /* Setting Time Segment 2 in BTR Register */
    btr1 |= (bt->phase_seg2 - 1) << XCAN_BTR_TS2_SHIFT; // 4
   // 표준에 지정된 위상 세그먼트2를 나타낸다.
   // 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) BTR에 TS2참조
 
    /* Setting Synchronous jump width in BTR Register */
    btr1 |= (bt->sjw - 1) << XCAN_BTR_SJW_SHIFT;  // 7 	
    // 표준에 지정된 동기화 점프 폭을 나타낸다.
    // 자세한 사항은 ug585 B.5 CAN Controller에 Register (can) BTR에 SJW참조
 
 
	priv->write_reg(priv, XCAN_BRPR_OFFSET, btr0);      	
// CAN레지스터(XCAN_BRPR_OFFSET)에 데이터(btr0)를 쓴다.
    priv->write_reg(priv, XCAN_BTR_OFFSET, btr1);       	
// CAN레지스터(XCAN_BTR_OFFSET)에 데이터(btr1)를 쓴다.
 
    netdev_dbg(ndev, "BRPR=0x%08x, BTR=0x%08x\n",		
// netdev_dbg( _dev, format, args ) 
// ADS : 어딘가에 출력을 하려고 하나? 
   		 priv->read_reg(priv, XCAN_BRPR_OFFSET),     	
// CAN레지스터(XCAN_BRPR_OFFSET)에 데이터를 읽는것
   		 priv->read_reg(priv, XCAN_BTR_OFFSET));     	
// CAN레지스터(XCAN_BTR_OFFSET)에 데이터를 읽는것
 
    return 0;
}
 
/**
 * xcan_chip_start - This the drivers start routine
 * @ndev:    Pointer to net_device structure
 *
 * This is the drivers start routine.
 * Based on the State of the CAN device it puts
 * the CAN device into a proper mode.
   이것은 드라이버 시작 루틴입니다. 
   CAN 장치의 상태에 따라 CAN 장치를 적절한 모드로 전환합니다.
 *
 * Return: 0 on success and failure value on error
 */
static int xcan_chip_start(struct net_device *ndev)
{
    struct xcan_priv *priv = netdev_priv(ndev);
    u32 reg_msr, reg_sr_mask;
    int err;
    unsigned long timeout;
 
    /* Check if it is in reset mode */
    err = set_reset_mode(ndev); 
   //err=0이면 CAN디바이스 모드를 리셋. err= 0이하면 ETIMEOUT
    if (err < 0)	// timeout이면 ETIMEOUT을 반환한다.
   	 return err;
 
    err = xcan_set_bittiming(ndev); 	
    //err=0이면 bit timing루틴을 설정, err=0이하이면 EPERM
    if (err < 0)	
     //구성준비가 안되어 있다면 EPERM(작동이 허용되지 않는다.) 반환한다.
   	 return err;
 
    /* Enable interrupts 
XCAN_INTR_ALL 
(XCAN_IXR_TXOK_MASK |   // TX successful intr
XCAN_IXR_BSOFF_MASK |  // Bus off interrupt
XCAN_IXR_WKUP_MASK |   // Wake up interrupt
XCAN_IXR_SLP_MASK |       // Sleep interrupt
XCAN_IXR_RXNEMP_MASK |  // RX FIFO NotEmpty intr
XCAN_IXR_ERROR_MASK |    // Error interrupt
XCAN_IXR_RXOFLW_MASK |  // RX FIFO Overflow intr
XCAN_IXR_ARBLST_MASK)    // Arbitration lost intr
인터럽트의 종류
*/
 
    priv->write_reg(priv, XCAN_IER_OFFSET, XCAN_INTR_ALL);  
// CAN레지스터(XCAN_IER_OFFSET)에 
데이터(XCAN_INTR_ALL-특정인터럽트가 활성화 되어있을경우 ture를 반환)를 쓴다.
 
    /* Check whether it is loopback mode or normal mode  */
    if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK) {  
 //CAN 데이터 구조체 안에 ctrlmode가 활성화되어있고 루프백모드가 활성화 되어있는지
 // 루프백 모드가 활성화되어 있으면 true
   	 reg_msr = XCAN_MSR_LBACK_MASK;  	//reg_msr = Loop back mode select
   	 reg_sr_mask = XCAN_SR_LBACK_MASK;   //reg_sr_mask = Loop back mode
    } else { // 루프백 모드 외(일반 모드) 인 경우 
   	 reg_msr = 0x0;  //선택 안함
   	 reg_sr_mask = XCAN_SR_NORMAL_MASK;  // reg_sr_mask = Normal mode
    }
 
    priv->write_reg(priv, XCAN_MSR_OFFSET, reg_msr);	
// CAN레지스터(XCAN_MSR_OFFSET-Mode select)에 데이터(reg_msr-선택한 모드)를 쓴다.
    priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_CEN_MASK);  
// CAN레지스터(XCAN_SRR_OFFSET -Software reset )에 데이터(XCAN_SRR_CEN_MASK-CAN enable)를 쓴다.
 
    timeout = jiffies + XCAN_TIMEOUT;	
// jiffies이란? 시스템 내의 전역적인 변수로써 초당 HZ값 만큼 숫자가 증가하게 된다.
// timeout = 근복적으로 gettimeofday 에서 가져오는 어떤 수 + (1 * HZ)
    while (!(priv->read_reg(priv, XCAN_SR_OFFSET) & reg_sr_mask)) {	//CAN레지스터(XCAN_SR_OFFSET)에 데이터를 읽는것 & Loop back mode또는 Normal mode인지(reg_sr_mask)
   	 if (time_after(jiffies, timeout)) {	// jiffies가 timeout보다 크면 true를 반환
						// time_after는 jiffies.h 에 정의되있음 
   		 netdev_warn(ndev,
   			 "timed out for correct mode\n");	//모드 선택에 대해 시간 초과됨 
   		 return -ETIMEDOUT;		// ETIMEDOUT :접속 타임 아웃을 리턴
   	 }
    }
    netdev_dbg(ndev, "status:#x%08x\n",	// netdev_dbg( _dev, format, args ) 형태 
   		 priv->read_reg(priv, XCAN_SR_OFFSET));	
// CAN레지스터(XCAN_SR_OFFSET)에 데이터를 읽는것(상태 출력)
 
    priv->can.state = CAN_STATE_ERROR_ACTIVE;	
//CAN 데이터 구조체에 있는 state는 RX(수신단자)/TX(송신단자) error count < 96
// ADS : 이게 무슨 의미가 있는지 잘 모르겠넹.
    return 0;
}
 
/**
 * xcan_do_set_mode - This sets the mode of the driver
   이것은 드라이버의 모드를 설정합니다
 * @ndev:    Pointer to net_device structure
 * @mode:    Tells the mode of the driver
 *
 * This check the drivers state and calls the
 * the corresponding modes to set.
 * 드라이버 상태를 확인하고 해당 모드를 설정합니다.
 * Return: 0 on success and failure value on error
 */
static int xcan_do_set_mode(struct net_device *ndev, enum can_mode mode)
{
    int ret;
 
    switch (mode) { // 드라이버 모드에 대한 스위치 구문
    case CAN_MODE_START:	// CAN모드 시작이면
   	 ret = xcan_chip_start(ndev);	//드라이버 시작 루틴
   	 if (ret < 0) {  //0보다 작으면 구성이 안되었거나 타임아웃으로 에러
   		 netdev_err(ndev, "xcan_chip_start failed!\n");
   		 return ret; //에러 반환(ETIMEOUT,EPERM)
   	 }
   	 netif_wake_queue(ndev); //네트워킹 시스템을 호출하여 패킷전송을 다시 시작한다.
   	 break;
    default:
   	 ret = -EOPNOTSUPP;  //CAN모드 시작이 안되면 ,EOPNOTSUPP : 전송 끝점에서 작업이 지원되지 않는다. (Operation not supported on transport endpoint)
   	 break;
    }
 
    return ret; // Return: 0 on success and failure value on error
}
 
/**
 * xcan_start_xmit - Starts the transmission
                                전송을 시작합니다.
 * @skb:    sk_buff pointer that contains data to be Txed
 * @ndev:    Pointer to net_device structure
 *
 * This function is invoked from upper layers to initiate transmission. This
 * function uses the next available free txbuff and populates their fields to
 * start the transmission.
이 기능은 상위 레이어에서 전송을 시작하기 위해 호출됩니다. 
이 함수는 다음 사용 가능한 free txbuff를 사용하고 필드를 채워 전송을 시작합니다.
 *
 * Return: 0 on success and failure value on error
 */
static int xcan_start_xmit(struct sk_buff *skb, struct net_device *ndev)
// sk_buff 구조체 : 소켓 버퍼. 구조체 안에 데이터가 중요해 보임
{
    struct xcan_priv *priv = netdev_priv(ndev);
    struct net_device_stats *stats = &ndev->stats;
   // net_device_stats : unsigned long 으로 상태변수 여러개 선언되있음. 
    struct can_frame *cf = (struct can_frame *)skb->data;
  // data : 데이터 헤드 포인터. 
  // 아마도 데이터의 시작부를 가리키기 위해 사용하는게 아닐까..
    u32 id, dlc, data[2] = {0, 0};
 
    if (can_dropped_invalid_skb(ndev, skb)) 
//유효한 CAN프레임을 가지고 있지 않으면 주어진 소켓 버퍼를 버린다.
   	 return NETDEV_TX_OK; // NETDEV_TX_OK : driver took care of packet
 
    /* Check if the TX buffer is full */
    if (unlikely(priv->read_reg(priv, XCAN_SR_OFFSET) &  
// unlikely는 컴파일러에게 해당 분기문에서 거짓인 경우가 더많을 것이라는 정보를 주는것.
   		 XCAN_SR_TXFLL_MASK)) {  	
// CAN레지스터(XCAN_SR_OFFSET)에 데이터를 읽는것과 TX FIFO is full
// SR_OFFSET 상태 레지스터에 TX FIFO가 풀이면 비트를 쓴다. 
   	 netif_stop_queue(ndev); 	// stop transmitted packets
   	 netdev_err(ndev, "BUG!, TX FIFO full when queue awake!\n");
   	 return NETDEV_TX_BUSY;  //패킷을 전송할 수 없다. 나중에 시도해라
 
    }
 
    /* Watch carefully on the bit sequence */
  if (cf->can_id & CAN_EFF_FLAG) {	
/*
can_id(can_id:  CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition) 와 CAN_EFF_FLAG : valid bits in CAN ID for frame formats extended frame format, 
extended frame format (EFF) / standard frame format ( SFF )
확장형 EFF 포멧과 can_id 를 &연산 한다. 
*/ 
 
 /* Extended CAN ID format */
/*
can_id(can_id:  CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition) & CAN_EFF_MASK(extended frame format(EFF))  <<  Extended Message Identifier(XCAN_IDR_ID2_SHIFT) & Extended message ident(XCAN_IDR_ID2_MASK)
*/ 
 
id = ((cf->can_id & CAN_EFF_MASK) << XCAN_IDR_ID2_SHIFT) &    XCAN_IDR_ID2_MASK;
 
/*
대체 뭐하는 부분인지 모르겠네 ㅡㅡ;;;;;; 
 can_id(can_id:  CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition) &
CAN_EFF_MASK(extended frame format(EFF)) >>
*/
id |= (((cf->can_id & CAN_EFF_MASK) >>   		 
(CAN_EFF_ID_BITS - CAN_SFF_ID_BITS))  << //29-11
XCAN_IDR_ID1_SHIFT) & XCAN_IDR_ID1_MASK;	
//XCAN_IDR_ID1_SHIFT(Standard Messg Identifier(21)) & 
  XCAN_IDR_ID1_MASK(Standard msg identifier(0xFFE00000))
 
 /* The substibute remote TX request bit should be "1"
 * for extended frames as in the Xilinx CAN datasheet
 */
id |= XCAN_IDR_IDE_MASK | XCAN_IDR_SRR_MASK;	// Identifier extension(0x00080000) | Substitute remote TXreq/(0x00100000)
 
   	 if (cf->can_id & CAN_RTR_FLAG)  //can_id(can_id:  CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition) & remote transmission request(0x40000000U)
   		 /* Extended frames remote TX request */
   		 id |= XCAN_IDR_RTR_MASK;	// Remote TX request(0x00000001)
    } else {
   	 /* Standard CAN ID format */
   	 id = ((cf->can_id & CAN_SFF_MASK) << XCAN_IDR_ID1_SHIFT) &  //can_id(can_id:  CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition) & standard frame format (SFF) << Standard Messg Identifier(21)
   		 XCAN_IDR_ID1_MASK;  	// Standard msg identifier(0xFFE00000)
 
   	 if (cf->can_id & CAN_RTR_FLAG) //can_id(can_id:  CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition) & remote transmission request(0x40000000U)
   		 /* Standard frames remote TX request */
   		 id |= XCAN_IDR_SRR_MASK;	// Substitute remote TXreq(0x00100000)
    }
 
    dlc = cf->can_dlc << XCAN_DLCR_DLC_SHIFT;	//// can_dlc(can_dlc에는 data [] 바이트 배열에 사용 된 바이트 수가 들어 있습니다) << Data length code(28)
 
    if (cf->can_dlc > 0)
   	 data[0] = be32_to_cpup((__be32 *)(cf->data + 0));   // be32_to_cpup는 "(__be32 *)(cf->data + 0)"에 지정된 주소에서 데이터를 읽은 다음 Big Endian에서 프로세서의 기본 Little Endian으로 변환하므로 "data[0]"에 포함될 것으로 예상되는 정수가 포함됩니다.
    if (cf->can_dlc > 4)
   	 data[1] = be32_to_cpup((__be32 *)(cf->data + 4));   // be32_to_cpup는 "(__be32 *)(cf->data + 4)"에 지정된 주소에서 데이터를 읽은 다음 Big Endian에서 프로세서의 기본 Little Endian으로 변환하므로 "data[1]"에 포함될 것으로 예상되는 정수가 포함됩니다.
 
    can_put_echo_skb(skb, ndev, priv->tx_head % priv->tx_max);		// skb를 루프에 스택에 놓고 나중에 로컬로 백업합니다.
	priv->tx_head++;    //Tx CAN packets ready to send on the queue증가
 
    priv->write_reg(priv, XCAN_TXFIFO_ID_OFFSET, id);   // CAN레지스터(XCAN_TXFIFO_ID_OFFSET: TX FIFO ID)에 데이터(id)를 쓴다.
    
    /* If the CAN frame is RTR frame this write triggers tranmission */
    priv->write_reg(priv, XCAN_TXFIFO_DLC_OFFSET, dlc); // CAN레지스터(XCAN_TXFIFO_DLC_OFFSET: TX FIFO DLC)에 데이터(dlc)를 쓴다.
 
    if (!(cf->can_id & CAN_RTR_FLAG)) { //can_id(can_id:  CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition) & remote transmission request(0x40000000U)
   	 priv->write_reg(priv, XCAN_TXFIFO_DW1_OFFSET, data[0]); // CAN레지스터(XCAN_TXFIFO_DW1_OFFSET: TX FIFO Data Word 1)에 데이터(data[0])를 쓴다.
   	 /* If the CAN frame is Standard/Extended frame this
   	  * write triggers tranmission
   	  */
   	 priv->write_reg(priv, XCAN_TXFIFO_DW2_OFFSET, data[1]); // CAN레지스터(XCAN_TXFIFO_DW1_OFFSET: TX FIFO Data Word 1)에 데이터(data[0])를 쓴다.
   	 stats->tx_bytes += cf->can_dlc; // tx_bytes(송신단자바이트) + can_dlc(can_dlc에는 data [] 바이트 배열에 사용 된 바이트 수가 들어 있습니다
    }
 
    /* Check if the TX buffer is full */
    if ((priv->tx_head - priv->tx_tail) == priv->tx_max)	//tx버퍼가 가득 찼다면
   	 netif_stop_queue(ndev); // stop transmitted packets
 
    return NETDEV_TX_OK;	// NETDEV_TX_OK : driver took care of packet
}
 
/**
 * xcan_rx -  Is called from CAN isr to complete the received
 *   	 frame  processing
 * @ndev:    Pointer to net_device structure
 *
 * This function is invoked from the CAN isr(poll) to process the Rx frames. It
 * does minimal processing and invokes "netif_receive_skb" to complete further
 * processing.
 * Return: 1 on success and 0 on failure.
 */
static int xcan_rx(struct net_device *ndev)
{
    struct xcan_priv *priv = netdev_priv(ndev);
    struct net_device_stats *stats = &ndev->stats;
    struct can_frame *cf;
    struct sk_buff *skb;
    u32 id_xcan, dlc, data[2] = {0, 0};
 
    skb = alloc_can_skb(ndev, &cf);
    if (unlikely(!skb)) {
   	 stats->rx_dropped++;
   	 return 0;
    }
 
    /* Read a frame from Xilinx zynq CANPS */
    id_xcan = priv->read_reg(priv, XCAN_RXFIFO_ID_OFFSET);
    dlc = priv->read_reg(priv, XCAN_RXFIFO_DLC_OFFSET) >>
   			 XCAN_DLCR_DLC_SHIFT;
 
    /* Change Xilinx CAN data length format to socketCAN data format */
    cf->can_dlc = get_can_dlc(dlc);
 
    /* Change Xilinx CAN ID format to socketCAN ID format */
    if (id_xcan & XCAN_IDR_IDE_MASK) {
   	 /* The received frame is an Extended format frame */
   	 cf->can_id = (id_xcan & XCAN_IDR_ID1_MASK) >> 3;
   	 cf->can_id |= (id_xcan & XCAN_IDR_ID2_MASK) >>
   			 XCAN_IDR_ID2_SHIFT;
   	 cf->can_id |= CAN_EFF_FLAG;
   	 if (id_xcan & XCAN_IDR_RTR_MASK)
   		 cf->can_id |= CAN_RTR_FLAG;
    } else {
   	 /* The received frame is a standard format frame */
   	 cf->can_id = (id_xcan & XCAN_IDR_ID1_MASK) >>
   			 XCAN_IDR_ID1_SHIFT;
   	 if (id_xcan & XCAN_IDR_SRR_MASK)
   		 cf->can_id |= CAN_RTR_FLAG;
    }
 
    /* DW1/DW2 must always be read to remove message from RXFIFO */
    data[0] = priv->read_reg(priv, XCAN_RXFIFO_DW1_OFFSET);
    data[1] = priv->read_reg(priv, XCAN_RXFIFO_DW2_OFFSET);
 
    if (!(cf->can_id & CAN_RTR_FLAG)) {
   	 /* Change Xilinx CAN data format to socketCAN data format */
   	 if (cf->can_dlc > 0)
   		 *(__be32 *)(cf->data) = cpu_to_be32(data[0]);
   	 if (cf->can_dlc > 4)
   		 *(__be32 *)(cf->data + 4) = cpu_to_be32(data[1]);
    }
 
    stats->rx_bytes += cf->can_dlc;
    stats->rx_packets++;
    netif_receive_skb(skb);
 
    return 1;
}
 
static void xcan_chip_stop(struct net_device *ndev);
/**
 * xcan_err_interrupt - error frame Isr
 * @ndev:    net_device pointer
 * @isr:    interrupt status register value
 *
 * This is the CAN error interrupt and it will
 * check the the type of error and forward the error
 * frame to upper layers.
 */
static void xcan_err_interrupt(struct net_device *ndev, u32 isr)
{
    struct xcan_priv *priv = netdev_priv(ndev);
    struct net_device_stats *stats = &ndev->stats;
    struct can_frame *cf;
    struct sk_buff *skb;
    u32 err_status, status, txerr = 0, rxerr = 0;
 
    skb = alloc_can_err_skb(ndev, &cf);
 
    err_status = priv->read_reg(priv, XCAN_ESR_OFFSET);
    priv->write_reg(priv, XCAN_ESR_OFFSET, err_status);
    txerr = priv->read_reg(priv, XCAN_ECR_OFFSET) & XCAN_ECR_TEC_MASK;
    rxerr = ((priv->read_reg(priv, XCAN_ECR_OFFSET) &
   		 XCAN_ECR_REC_MASK) >> XCAN_ESR_REC_SHIFT);
    status = priv->read_reg(priv, XCAN_SR_OFFSET);
 
    if (isr & XCAN_IXR_BSOFF_MASK) {
   	 priv->can.state = CAN_STATE_BUS_OFF;
   	 priv->can.can_stats.bus_off++;
   	 /* Leave device in Config Mode in bus-off state */
   	 priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);
   	 can_bus_off(ndev);
   	 if (skb)
   		 cf->can_id |= CAN_ERR_BUSOFF;
    } else if ((status & XCAN_SR_ESTAT_MASK) == XCAN_SR_ESTAT_MASK) {
   	 priv->can.state = CAN_STATE_ERROR_PASSIVE;
   	 priv->can.can_stats.error_passive++;
   	 if (skb) {
   		 cf->can_id |= CAN_ERR_CRTL;
   		 cf->data[1] = (rxerr > 127) ?
   				 CAN_ERR_CRTL_RX_PASSIVE :
   				 CAN_ERR_CRTL_TX_PASSIVE;
   		 cf->data[6] = txerr;
   		 cf->data[7] = rxerr;
   	 }
    } else if (status & XCAN_SR_ERRWRN_MASK) {
   	 priv->can.state = CAN_STATE_ERROR_WARNING;
   	 priv->can.can_stats.error_warning++;
   	 if (skb) {
   		 cf->can_id |= CAN_ERR_CRTL;
   		 cf->data[1] |= (txerr > rxerr) ?
   				 CAN_ERR_CRTL_TX_WARNING :
   				 CAN_ERR_CRTL_RX_WARNING;
   		 cf->data[6] = txerr;
   		 cf->data[7] = rxerr;
   	 }
    }
 
    /* Check for Arbitration lost interrupt */
    if (isr & XCAN_IXR_ARBLST_MASK) {
   	 priv->can.can_stats.arbitration_lost++;
   	 if (skb) {
   		 cf->can_id |= CAN_ERR_LOSTARB;
   		 cf->data[0] = CAN_ERR_LOSTARB_UNSPEC;
   	 }
    }
 
    /* Check for RX FIFO Overflow interrupt */
    if (isr & XCAN_IXR_RXOFLW_MASK) {
   	 stats->rx_over_errors++;
   	 stats->rx_errors++;
   	 xcan_chip_stop(ndev);
   	 xcan_chip_start(ndev);
   	 if (skb) {
   		 cf->can_id |= CAN_ERR_CRTL;
   		 cf->data[1] |= CAN_ERR_CRTL_RX_OVERFLOW;
   	 }
    }
 
    /* Check for error interrupt */
    if (isr & XCAN_IXR_ERROR_MASK) {
   	 if (skb) {
   		 cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
   		 cf->data[2] |= CAN_ERR_PROT_UNSPEC;
   	 }
 
   	 /* Check for Ack error interrupt */
   	 if (err_status & XCAN_ESR_ACKER_MASK) {
   		 stats->tx_errors++;
   		 if (skb) {
   			 cf->can_id |= CAN_ERR_ACK;
   			 cf->data[3] |= CAN_ERR_PROT_LOC_ACK;
   		 }
   	 }
 
   	 /* Check for Bit error interrupt */
   	 if (err_status & XCAN_ESR_BERR_MASK) {
   		 stats->tx_errors++;
   		 if (skb) {
   			 cf->can_id |= CAN_ERR_PROT;
   			 cf->data[2] = CAN_ERR_PROT_BIT;
   		 }
   	 }
 
   	 /* Check for Stuff error interrupt */
   	 if (err_status & XCAN_ESR_STER_MASK) {
   		 stats->rx_errors++;
   		 if (skb) {
   			 cf->can_id |= CAN_ERR_PROT;
   			 cf->data[2] = CAN_ERR_PROT_STUFF;
   		 }
   	 }
 
   	 /* Check for Form error interrupt */
   	 if (err_status & XCAN_ESR_FMER_MASK) {
   		 stats->rx_errors++;
   		 if (skb) {
   			 cf->can_id |= CAN_ERR_PROT;
   			 cf->data[2] = CAN_ERR_PROT_FORM;
   		 }
   	 }
 
   	 /* Check for CRC error interrupt */
   	 if (err_status & XCAN_ESR_CRCER_MASK) {
   		 stats->rx_errors++;
   		 if (skb) {
   			 cf->can_id |= CAN_ERR_PROT;
   			 cf->data[3] = CAN_ERR_PROT_LOC_CRC_SEQ |
   					 CAN_ERR_PROT_LOC_CRC_DEL;
   		 }
   	 }
   		 priv->can.can_stats.bus_error++;
    }
 
    if (skb) {
   	 stats->rx_packets++;
   	 stats->rx_bytes += cf->can_dlc;
   	 netif_rx(skb);
    }
 
    netdev_dbg(ndev, "%s: error status register:0x%x\n",
   		 __func__, priv->read_reg(priv, XCAN_ESR_OFFSET));
}
 
/**
 * xcan_state_interrupt - It will check the state of the CAN device
 * @ndev:    net_device pointer
 * @isr:    interrupt status register value
 *
 * This will checks the state of the CAN device
 * and puts the device into appropriate state.
 */
static void xcan_state_interrupt(struct net_device *ndev, u32 isr)
{
    struct xcan_priv *priv = netdev_priv(ndev);
 
    /* Check for Sleep interrupt if set put CAN device in sleep state */
    if (isr & XCAN_IXR_SLP_MASK)
   	 priv->can.state = CAN_STATE_SLEEPING;
 
    /* Check for Wake up interrupt if set put CAN device in Active state */
    if (isr & XCAN_IXR_WKUP_MASK)
   	 priv->can.state = CAN_STATE_ERROR_ACTIVE;
}
 
/**
 * xcan_rx_poll - Poll routine for rx packets (NAPI)
 * @napi:    napi structure pointer
 * @quota:    Max number of rx packets to be processed.
 *
 * This is the poll routine for rx part.
 * It will process the packets maximux quota value.
 *
 * Return: number of packets received
 */
static int xcan_rx_poll(struct napi_struct *napi, int quota)
{
    struct net_device *ndev = napi->dev;
    struct xcan_priv *priv = netdev_priv(ndev);
    u32 isr, ier;
    int work_done = 0;
 
    isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
    while ((isr & XCAN_IXR_RXNEMP_MASK) && (work_done < quota)) {
   	 work_done += xcan_rx(ndev);
   	 priv->write_reg(priv, XCAN_ICR_OFFSET, XCAN_IXR_RXNEMP_MASK);
   	 isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
    }
 
    if (work_done)
   	 can_led_event(ndev, CAN_LED_EVENT_RX);
 
    if (work_done < quota) {
   	 napi_complete(napi);
   	 ier = priv->read_reg(priv, XCAN_IER_OFFSET);
   	 ier |= XCAN_IXR_RXNEMP_MASK;
   	 priv->write_reg(priv, XCAN_IER_OFFSET, ier);
    }
    return work_done;
}
 
/**
 * xcan_tx_interrupt - Tx Done Isr
 * @ndev:    net_device pointer
 * @isr:    Interrupt status register value
 */
static void xcan_tx_interrupt(struct net_device *ndev, u32 isr)
{
    struct xcan_priv *priv = netdev_priv(ndev);
    struct net_device_stats *stats = &ndev->stats;
 
    while ((priv->tx_head - priv->tx_tail > 0) &&
   		 (isr & XCAN_IXR_TXOK_MASK)) {
   	 priv->write_reg(priv, XCAN_ICR_OFFSET, XCAN_IXR_TXOK_MASK);
   	 can_get_echo_skb(ndev, priv->tx_tail %
   				 priv->tx_max);
   	 priv->tx_tail++;
   	 stats->tx_packets++;
   	 isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
    }
    can_led_event(ndev, CAN_LED_EVENT_TX);
    netif_wake_queue(ndev);
}
 
/**
 * xcan_interrupt - CAN Isr
 * @irq:    irq number
 * @dev_id:    device id poniter
 *
 * This is the xilinx CAN Isr. It checks for the type of interrupt
 * and invokes the corresponding ISR.
 *
 * Return:
 * IRQ_NONE - If CAN device is in sleep mode, IRQ_HANDLED otherwise
 */
static irqreturn_t xcan_interrupt(int irq, void *dev_id)
{
    struct net_device *ndev = (struct net_device *)dev_id;
    struct xcan_priv *priv = netdev_priv(ndev);
    u32 isr, ier;
 
    /* Get the interrupt status from Xilinx CAN */
    isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
    if (!isr)
   	 return IRQ_NONE;
 
    /* Check for the type of interrupt and Processing it */
    if (isr & (XCAN_IXR_SLP_MASK | XCAN_IXR_WKUP_MASK)) {
   	 priv->write_reg(priv, XCAN_ICR_OFFSET, (XCAN_IXR_SLP_MASK |
   			 XCAN_IXR_WKUP_MASK));
   	 xcan_state_interrupt(ndev, isr);
    }
 
    /* Check for Tx interrupt and Processing it */
    if (isr & XCAN_IXR_TXOK_MASK)
   	 xcan_tx_interrupt(ndev, isr);
 
    /* Check for the type of error interrupt and Processing it */
    if (isr & (XCAN_IXR_ERROR_MASK | XCAN_IXR_RXOFLW_MASK |
   		 XCAN_IXR_BSOFF_MASK | XCAN_IXR_ARBLST_MASK)) {
   	 priv->write_reg(priv, XCAN_ICR_OFFSET, (XCAN_IXR_ERROR_MASK |
   			 XCAN_IXR_RXOFLW_MASK | XCAN_IXR_BSOFF_MASK |
   			 XCAN_IXR_ARBLST_MASK));
   	 xcan_err_interrupt(ndev, isr);
    }
 
    /* Check for the type of receive interrupt and Processing it */
    if (isr & XCAN_IXR_RXNEMP_MASK) {
   	 ier = priv->read_reg(priv, XCAN_IER_OFFSET);
   	 ier &= ~XCAN_IXR_RXNEMP_MASK;
   	 priv->write_reg(priv, XCAN_IER_OFFSET, ier);
   	 napi_schedule(&priv->napi);
    }
    return IRQ_HANDLED;
}
 
/**
 * xcan_chip_stop - Driver stop routine
 * @ndev:    Pointer to net_device structure
 *
 * This is the drivers stop routine. It will disable the
 * interrupts and put the device into configuration mode.
 */
static void xcan_chip_stop(struct net_device *ndev)
{
    struct xcan_priv *priv = netdev_priv(ndev);
    u32 ier;
 
    /* Disable interrupts and leave the can in configuration mode */
    ier = priv->read_reg(priv, XCAN_IER_OFFSET);
    ier &= ~XCAN_INTR_ALL;
    priv->write_reg(priv, XCAN_IER_OFFSET, ier);
    priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);
    priv->can.state = CAN_STATE_STOPPED;
}
 
/**
 * xcan_open - Driver open routine
 * @ndev:    Pointer to net_device structure
 *
 * This is the driver open routine.
 * Return: 0 on success and failure value on error
 */
static int xcan_open(struct net_device *ndev)
{
    struct xcan_priv *priv = netdev_priv(ndev);
    int ret;
 
    ret = pm_runtime_get_sync(priv->dev);
    if (ret < 0) {
   	 netdev_err(ndev, "%s: pm_runtime_get failed(%d)\n",
   			 __func__, ret);
   	 return ret;
    }
 
    ret = request_irq(ndev->irq, xcan_interrupt, priv->irq_flags,
   		 ndev->name, ndev);
    if (ret < 0) {
   	 netdev_err(ndev, "irq allocation for CAN failed\n");
   	 goto err;
    }
 
    /* Set chip into reset mode */
    ret = set_reset_mode(ndev);
    if (ret < 0) {
   	 netdev_err(ndev, "mode resetting failed!\n");
   	 goto err_irq;
    }
 
    /* Common open */
    ret = open_candev(ndev);
    if (ret)
   	 goto err_irq;
 
    ret = xcan_chip_start(ndev);
    if (ret < 0) {
   	 netdev_err(ndev, "xcan_chip_start failed!\n");
   	 goto err_candev;
    }
 
    can_led_event(ndev, CAN_LED_EVENT_OPEN);
    napi_enable(&priv->napi);
    netif_start_queue(ndev);
 
    return 0;
 
err_candev:
    close_candev(ndev);
err_irq:
    free_irq(ndev->irq, ndev);
err:
    pm_runtime_put(priv->dev);
 
    return ret;
}
 
/**
 * xcan_close - Driver close routine
 * @ndev:    Pointer to net_device structure
 *
 * Return: 0 always
 */
static int xcan_close(struct net_device *ndev)
{
    struct xcan_priv *priv = netdev_priv(ndev);
 
    netif_stop_queue(ndev);
    napi_disable(&priv->napi);
    xcan_chip_stop(ndev);
    free_irq(ndev->irq, ndev);
    close_candev(ndev);
 
    can_led_event(ndev, CAN_LED_EVENT_STOP);
    pm_runtime_put(priv->dev);
 
    return 0;
}
 
/**
 * xcan_get_berr_counter - error counter routine
 * @ndev:    Pointer to net_device structure
 * @bec:    Pointer to can_berr_counter structure
 *
 * This is the driver error counter routine.
 * Return: 0 on success and failure value on error
 */
static int xcan_get_berr_counter(const struct net_device *ndev,
   				 struct can_berr_counter *bec)
{
    struct xcan_priv *priv = netdev_priv(ndev);
    int ret;
 
    ret = pm_runtime_get_sync(priv->dev);
    if (ret < 0) {
   	 netdev_err(ndev, "%s: pm_runtime_get failed(%d)\n",
   			 __func__, ret);
   	 return ret;
    }
 
    bec->txerr = priv->read_reg(priv, XCAN_ECR_OFFSET) & XCAN_ECR_TEC_MASK;
    bec->rxerr = ((priv->read_reg(priv, XCAN_ECR_OFFSET) &
   		 XCAN_ECR_REC_MASK) >> XCAN_ESR_REC_SHIFT);
 
    pm_runtime_put(priv->dev);
 
    return 0;
}
 
 
static const struct net_device_ops xcan_netdev_ops = {
    .ndo_open    = xcan_open,
    .ndo_stop    = xcan_close,
    .ndo_start_xmit    = xcan_start_xmit,
    .ndo_change_mtu    = can_change_mtu,
};
 
/**
 * xcan_suspend - Suspend method for the driver
 * @dev:    Address of the device structure
 *
 * Put the driver into low power mode.
 * Return: 0 on success and failure value on error
 */
static int __maybe_unused xcan_suspend(struct device *dev)
{
    if (!device_may_wakeup(dev))
   	 return pm_runtime_force_suspend(dev);
 
    return 0;
}
 
/**
 * xcan_resume - Resume from suspend
 * @dev:    Address of the device structure
 *
 * Resume operation after suspend.
 * Return: 0 on success and failure value on error
 */
static int __maybe_unused xcan_resume(struct device *dev)
{
    if (!device_may_wakeup(dev))
   	 return pm_runtime_force_resume(dev);
 
    return 0;
 
}
 
/**
 * xcan_runtime_suspend - Runtime suspend method for the driver
 * @dev:    Address of the device structure
 *
 * Put the driver into low power mode.
 * Return: 0 always
 */
static int __maybe_unused xcan_runtime_suspend(struct device *dev)
{
    struct net_device *ndev = dev_get_drvdata(dev);
    struct xcan_priv *priv = netdev_priv(ndev);
 
    if (netif_running(ndev)) {
   	 netif_stop_queue(ndev);
   	 netif_device_detach(ndev);
    }
 
    priv->write_reg(priv, XCAN_MSR_OFFSET, XCAN_MSR_SLEEP_MASK);
    priv->can.state = CAN_STATE_SLEEPING;
 
    clk_disable_unprepare(priv->bus_clk);
    clk_disable_unprepare(priv->can_clk);
 
    return 0;
}
 
/**
 * xcan_runtime_resume - Runtime resume from suspend
 * @dev:    Address of the device structure
 *
 * Resume operation after suspend.
 * Return: 0 on success and failure value on error
 */
static int __maybe_unused xcan_runtime_resume(struct device *dev)
{
    struct net_device *ndev = dev_get_drvdata(dev);
    struct xcan_priv *priv = netdev_priv(ndev);
    int ret;
    u32 isr, status;
 
    ret = clk_prepare_enable(priv->bus_clk);
    if (ret) {
   	 dev_err(dev, "Cannot enable clock.\n");
   	 return ret;
    }
    ret = clk_prepare_enable(priv->can_clk);
    if (ret) {
   	 dev_err(dev, "Cannot enable clock.\n");
   	 clk_disable_unprepare(priv->bus_clk);
   	 return ret;
    }
 
    priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);
    isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
    status = priv->read_reg(priv, XCAN_SR_OFFSET);
 
    if (netif_running(ndev)) {
   	 if (isr & XCAN_IXR_BSOFF_MASK) {
   		 priv->can.state = CAN_STATE_BUS_OFF;
   		 priv->write_reg(priv, XCAN_SRR_OFFSET,
   				 XCAN_SRR_RESET_MASK);
   	 } else if ((status & XCAN_SR_ESTAT_MASK) ==
   				 XCAN_SR_ESTAT_MASK) {
   		 priv->can.state = CAN_STATE_ERROR_PASSIVE;
   	 } else if (status & XCAN_SR_ERRWRN_MASK) {
   		 priv->can.state = CAN_STATE_ERROR_WARNING;
   	 } else {
   		 priv->can.state = CAN_STATE_ERROR_ACTIVE;
   	 }
   	 netif_device_attach(ndev);
   	 netif_start_queue(ndev);
    }
 
    return 0;
}
 
static const struct dev_pm_ops xcan_dev_pm_ops = {
    SET_SYSTEM_SLEEP_PM_OPS(xcan_suspend, xcan_resume)
    SET_RUNTIME_PM_OPS(xcan_runtime_suspend, xcan_runtime_resume, NULL)
};
 
/**
 * xcan_probe - Platform registration call
 * @pdev:    Handle to the platform device structure
 *
 * This function does all the memory allocation and registration for the CAN
 * device.
 *
 * Return: 0 on success and failure value on error
 */
static int xcan_probe(struct platform_device *pdev)
{
    struct resource *res; /* IO mem resources */
    struct net_device *ndev;
    struct xcan_priv *priv;
    void __iomem *addr;
    int ret, rx_max, tx_max;
 
    /* Get the virtual base address for the device */
    res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    addr = devm_ioremap_resource(&pdev->dev, res);
    if (IS_ERR(addr)) {
   	 ret = PTR_ERR(addr);
   	 goto err;
    }
 
    ret = of_property_read_u32(pdev->dev.of_node, "tx-fifo-depth", &tx_max);
    if (ret < 0)
   	 goto err;
 
    ret = of_property_read_u32(pdev->dev.of_node, "rx-fifo-depth", &rx_max);
    if (ret < 0)
   	 goto err;
 
    /* Create a CAN device instance */
    ndev = alloc_candev(sizeof(struct xcan_priv), tx_max);
    if (!ndev)
   	 return -ENOMEM;
 
    priv = netdev_priv(ndev);
    priv->dev = &pdev->dev;
    priv->can.bittiming_const = &xcan_bittiming_const;
    priv->can.do_set_mode = xcan_do_set_mode;
    priv->can.do_get_berr_counter = xcan_get_berr_counter;
    priv->can.ctrlmode_supported = CAN_CTRLMODE_LOOPBACK |
   				 CAN_CTRLMODE_BERR_REPORTING;
    priv->reg_base = addr;
    priv->tx_max = tx_max;
 
    /* Get IRQ for the device */
    ndev->irq = platform_get_irq(pdev, 0);
    ndev->flags |= IFF_ECHO;    /* We support local echo */
 
    platform_set_drvdata(pdev, ndev);
    SET_NETDEV_DEV(ndev, &pdev->dev);
    ndev->netdev_ops = &xcan_netdev_ops;
 
    /* Getting the CAN can_clk info */
    priv->can_clk = devm_clk_get(&pdev->dev, "can_clk");
    if (IS_ERR(priv->can_clk)) {
   	 dev_err(&pdev->dev, "Device clock not found.\n");
   	 ret = PTR_ERR(priv->can_clk);
   	 goto err_free;
    }
    /* Check for type of CAN device */
    if (of_device_is_compatible(pdev->dev.of_node,
   			 	"xlnx,zynq-can-1.0")) {
   	 priv->bus_clk = devm_clk_get(&pdev->dev, "pclk");
   	 if (IS_ERR(priv->bus_clk)) {
   		 dev_err(&pdev->dev, "bus clock not found\n");
   		 ret = PTR_ERR(priv->bus_clk);
   		 goto err_free;
   	 }
    } else {
   	 priv->bus_clk = devm_clk_get(&pdev->dev, "s_axi_aclk");
   	 if (IS_ERR(priv->bus_clk)) {
   		 dev_err(&pdev->dev, "bus clock not found\n");
   		 ret = PTR_ERR(priv->bus_clk);
   		 goto err_free;
   	 }
    }
 
    priv->write_reg = xcan_write_reg_le;
    priv->read_reg = xcan_read_reg_le;
 
    pm_runtime_enable(&pdev->dev);
    ret = pm_runtime_get_sync(&pdev->dev);
    if (ret < 0) {
   	 netdev_err(ndev, "%s: pm_runtime_get failed(%d)\n",
   		 __func__, ret);
   	 goto err_pmdisable;
    }
 
    if (priv->read_reg(priv, XCAN_SR_OFFSET) != XCAN_SR_CONFIG_MASK) {
   	 priv->write_reg = xcan_write_reg_be;
   	 priv->read_reg = xcan_read_reg_be;
    }
 
    priv->can.clock.freq = clk_get_rate(priv->can_clk);
 
    netif_napi_add(ndev, &priv->napi, xcan_rx_poll, rx_max);
 
    ret = register_candev(ndev);
    if (ret) {
   	 dev_err(&pdev->dev, "fail to register failed (err=%d)\n", ret);
   	 goto err_disableclks;
    }
 
    devm_can_led_init(ndev);
 
    pm_runtime_put(&pdev->dev);
 
    netdev_dbg(ndev, "reg_base=0x%p irq=%d clock=%d, tx fifo depth:%d\n",
   		 priv->reg_base, ndev->irq, priv->can.clock.freq,
   		 priv->tx_max);
 
    return 0;
 
err_disableclks:
    pm_runtime_put(priv->dev);
err_pmdisable:
    pm_runtime_disable(&pdev->dev);
err_free:
    free_candev(ndev);
err:
    return ret;
}
 
/**
 * xcan_remove - Unregister the device after releasing the resources
 * @pdev:    Handle to the platform device structure
 *
 * This function frees all the resources allocated to the device.
 * Return: 0 always
 */
static int xcan_remove(struct platform_device *pdev)
{
    struct net_device *ndev = platform_get_drvdata(pdev);
    struct xcan_priv *priv = netdev_priv(ndev);
 
    unregister_candev(ndev);
    pm_runtime_disable(&pdev->dev);
    netif_napi_del(&priv->napi);
    free_candev(ndev);
 
    return 0;
}
 
/* Match table for OF platform binding */
static struct of_device_id xcan_of_match[] = {
    { .compatible = "xlnx,zynq-can-1.0", },
    { .compatible = "xlnx,axi-can-1.00.a", },
    { /* end of list */ },
};
MODULE_DEVICE_TABLE(of, xcan_of_match);
 
static struct platform_driver xcan_driver = {
    .probe = xcan_probe,
    .remove    = xcan_remove,
    .driver    = {
   	 .name = DRIVER_NAME,
   	 .pm = &xcan_dev_pm_ops,
   	 .of_match_table    = xcan_of_match,
    },
};
 
module_platform_driver(xcan_driver);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Xilinx Inc");
MODULE_DESCRIPTION("Xilinx CAN interface");
 
 
 
