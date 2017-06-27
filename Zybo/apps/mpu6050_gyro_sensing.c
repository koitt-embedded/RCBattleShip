#include <stdio.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define I2C_FILE_NAME	"/dev/i2c-0"
#define MPU6050_ADDR	0x68
#define PWR_MGMT_1		0x3B
#define ACCEL_CONFIG	0x1C
#define ACCEL_XOUT_H	0x3B
#define ACCEL_XOUT_L	0x3C
#define ACCEL_YOUT_H	0x3D
#define ACCEL_YOUT_L	0x3E
#define ACCEL_ZOUT_H	0x3F
#define ACCEL_ZOUT_L	0x40
#define X_H 			0
#define X_L 			1
#define Y_H 			2
#define Y_L 			3
#define Z_H 			4
#define Z_L 			5

int send_data(int fd, unsigned char wordRegister, unsigned char data);
int receive_data(int fd, unsigned char *acc_xyz);
void print_sensing_data(unsigned char *acc_xyz);

int main(int argc, char **argv) {
	int fd = 0;
	unsigned char acc_xyz[6] = {0};

	printf("Try to connect device\n");
	if((fd = open(I2C_FILE_NAME, O_RDWR)) < 0) {
		perror("---open device error : ");
		return -1;
	}
	printf("Successfully open device file\n");
	
	send_data(fd, PWR_MGMT_1, 0x0);
	send_data(fd, ACCEL_CONFIG, 0x18);
	while(1) {
		receive_data(fd, acc_xyz);
		print_sensing_data(acc_xyz);
	}

	return 0;
}

int send_data(int fd, unsigned char wordRegister, unsigned char data) {
	struct i2c_rdwr_ioctl_data msgset;
	struct i2c_msg msgs[1];
	unsigned char buf[2];

	buf[0] = wordRegister;
	buf[1] = data;

	msgs[0].addr = MPU6050_ADDR;
	msgs[0].flags = 0;
	msgs[0].len = sizeof(buf);
	msgs[0].buf = buf;

	msgset.msgs = msgs;
	msgset.nmsgs = 1;

	printf("Try to send data to 0x%x\n", wordRegister);
	if(ioctl(fd, I2C_RDWR, &msgset) < 0) {
		perror("---send_data error : ");
		return -1;
	}
	printf("Successfully sent data, word address : 0x%x, bit value : 0x%x\n", wordRegister, data);

	return 0;
}

int receive_data(int fd, unsigned char *acc_xyz) {
	struct i2c_rdwr_ioctl_data msgset;
	struct i2c_msg msgs[12];
	// unsigned char buf[12];
	unsigned char buf[6];
	int i;

	for(i=0; i<12; i++) {
		if(i%2) {
			// buf[i * 2] = ACCEL_XOUT_H + i;
			// buf[(i + 1) * 2] = acc_xyz[i / 2];
			buf[i / 2] = ACCEL_XOUT_H + i;

			msgs[i].addr = MPU6050_ADDR;
			msgs[i].flags = 0;
			msgs[i].len = 1;
			msgs[i].buf = buf[(i + 1) * 2];
		}else {
			msgs[i].addr = MPU6050_ADDR;
			msgs[i].flags = I2C_M_RD;
			msgs[i].len = 1;
			msgs[i].buf = acc_xyz[i / 2];
		}
	}

	msgset.msgs = msgs;
	msgset.nmsgs = 12;

	printf("Try to receive data from ");
	for(i=0; i<6; i++) printf("0x%x, ", ACCEL_XOUT_H + i);
	if(ioctl(fd, I2C_RDWR, &msgset) < 0) {
		perror("\n---receive_data error : ");
		return -1;
	}

	return 0;
}

void print_sensing_data(unsigned char *acc_xyz) {
	int i, j = 1;
	int xyz[3] = {0};
	for(i=1; i=<6; i++) {
		printf("[acc_xyz]--%d : %d\n", i, acc_xyz[i - 1]);
		if(i % 2) {
			xyz[i - j] = acc_xyz[i - 1];
			j ++;
		}else {
			xyz[i - j] << 8;
			xyz[i - j] |= acc_xyz[i - 1]
		}
	}
	printf("X : %d\n", xyz[0]);
	printf("Y : %d\n", xyz[1]);
	printf("Z : %d\n", xyz[2]);
}