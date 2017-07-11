#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "water_rocket_simulation.h"

// 표준 공기 밀도
#define	STANDARD_AIR_DENSITY		1.293
// 표준 대기압
#define STANDARD_ATMOSPHERE		101325
// 기체 상수
#define DRY_AIR_GAS_CONST		287.05
// 캘빈 상수
#define KELVIN_CONST			273.15
// 물의 밀도
#define WATER_DENSITY			1000.0
// kg/cm^2 -> Pa
#define KG_PER_CM_SQUARE_TO_PA		98066.5
// 1 atm -> 1 kg/cm^2
#define ATM_TO_KG_PER_CM_SQUARE		1.03323

float calc_pneumatic_density(float temper, float press)
{
	//return STANDARD_ATMOSPHERE / (DRY_AIR_GAS_CONST * (temper + KELVIN_CONST));
	return (press * STANDARD_ATMOSPHERE) / (DRY_AIR_GAS_CONST * (temper + KELVIN_CONST));
}

float calc_exhaust_velocity(float press)
{
	return sqrt((2 * (press - 1.0)) / WATER_DENSITY);
}

#if 0
float get_shr_with_convert_unit(float press)
{
	int i;
	float tmp, press_pa = press * STANDARD_ATMOSPHERE;

	for(i = 0; i < 11; i++)
	{
		if(press_pa > lashr_tbl[i][0] * KG_PER_CM_SQUARE_TO_PA &&
		   press_pa < lashr_tbl[i + 1][0] * KG_PER_CM_SQUARE_TO_PA)
		{
			float interval = lashr_tbl[i + 1][0] * KG_PER_CM_SQUARE_TO_PA - press_pa;
			tmp = (lashr_tbl[i][1] + (lashr_tbl[i + 1][1] - lashr_tbl[i][1])) *
			       KG_PER_CM_SQUARE_TO_PA * interval;
			return tmp;
		}
	}
}
#endif

float get_sat_shr_with_convert_unit(float press)
{
	int i;
	float tmp, press_kgcm2 = press * ATM_TO_KG_PER_CM_SQUARE;

	for(i = 0; i < 11; i++)
	{
		if(press_kgcm2 > sat_lashr_tbl[i][0] && press_kgcm2 < sat_lashr_tbl[i + 1][0])
		{
			float interval = sat_lashr_tbl[i + 1][0] - press_kgcm2;
			tmp = sat_lashr_tbl[i][1] + (sat_lashr_tbl[i + 1][1] - sat_lashr_tbl[i][1]) * interval;
			return tmp;
		}
	}
}

/* Water Thrust 부분에서 쇼부 봐야함
   Air Thrust 까지 진행되면 자세 제어가 불가능함 */
int main(void)
{
	// F_R = m_R * d(v_R) / dt = F_Th + F_G + F_D
	// F_Th(t) = v_e(t) * d(m_R) / dt
	// p(t) + 0.5 * ρ_Water * v_in^2 = p_0 + ρ_Water * 0.5 * v_E^2

	// v_E(t) = sqrt([2 * (p(t) - p_0)]/ρ_Water)
	// p(0) * V_A^γ(0) = p(t) * V_A^γ(t) => p(t) = p(0) * (V_A(t) / V_A(0))^-γ
	// p(t) = p(0) * ([V_A(0) + (V_W(0) - V_W(t))]/ V_A(0))^-γ
	//      = p(0) * (1 + [m_W(0) - m_W(t)] / [ρ_Water * V_A(0)])^-γ
	// p(t) = p(0) * (1 + [m_R(0) - m_A(0) - m_0 - m_R(t) + m_A(t) + m_0] / [ρ_Water * V_A(0)])^-γ
	//      = p(0) * (1 + [m_R(0) - m_R(t)] / [ρ_Water * V_A(0)])^-γ
	// d(m_R) / dt = d(m_W) / dt = ρ_Water * d(V_water) / dt = ρ_Water * A_N * v_E(t)

	// v_E(t) = sqrt([2 * (p(t) - p_0)]/ρ_A)
	// p(t) = p(t_0) * (V_A(t) / V_A(t_0))^-γ
	//      = p(t_0) * ([V_R + V_(A, o)(t)] / V_R)^-γ
	//      = p(t_0) * (1 + [m_(A, o)(t)] / [ρ_A * V_R])^-γ
	//      = p(t_0) * (1 + [m_(A, i)(t_0) - m_(A, i)(t)] / [ρ_A * V_R])^-γ
	// m_(A, i)(t_0) = m_(A, i)(0) = V_A(0) * ρ'_A(p) = V_A(0) * p(0) / (R_S * T)
	// d[m_(A, i)] / dt = ρ_A * A_N * v_E(t)

	// F_G = m_R(t) * g

	// F_D = 0.5 * c_D * ρ_A * A * v_R^2
	// F_D = -0.5 * c_D * ρ_A * A(v_R.v_R) * (v_R / ||v_R||)

	/* result */
	// m_R * (dv_R / dt) = v_e(t) * (dm_R / dt) + m_R(t) * g - 0.5 * c_D * ρ_A * A * (v_R.v_R) * (v_R / ||v_R||)

	// v_E(t) = sqrt([2 * (p(t) - p_0)] / ρ_Water)
	// p(t) = p(0) * (1 + [m_W(0) - m_W(t)] / [ρ_Water * V_A(0)])^-γ
	// dm_R / dt = ρ_Water * A_N * v_E(t)

	// v_E(t) = sqrt([2 * (p(t) - p_0)] / ρ_A)
	// p(t) = p(t_0) * (1 + [m_(A, i)(t_0) - m_(A, i)(t)] / [ρ_A * V_R])^-γ
	// dm_(A, i) / dt = ρ_A * A_N * v_E(t)

	/* 여기서 m_R 은 전체 로켓에 대한 질량이다.
	   v_R 은 로켓의 속도에 해당한다.
	   v_e 는 노즐에서의 배기 속도에 해당한다.
	   c_D 는 항력 계수다.
	   ρ_A 는 공기 밀도에 해당한다.

	   먼저 공기 밀도를 구해보도록 한다.
	   온도값은 공기압 센서를 통해서 가져와야 하는데 우선 11 ~ 30 도 사이라고 가정하고 만든다. */
	float air_dens, temper, press;

	/* Exhaust Velocity(배출 속도) */
	float water_exhaust_vel;

	/* Saturation Specific Heat Ratio(포화 비열비) */
	//float sat_sh_ratio;

	/* Specific Heat Ratio(포화 비열비) */
	float sh_ratio;

	srand(time(NULL));
	// 섭씨 온도
	temper = rand() % 20 + 11;
	// 1 ~ 6 기압 사이에서 사용하는 0.01 기준의 스케일 팩터
	press = (rand() % 501 + 100) / 100.0;

	/* 먼저 보일 샤를의 법칙을 적용한다.
	   밀도 = p / RT

	   밀도 단위 = kg / m^3
	   압력 = Pa
	   기체 상수 = 287.05 J / kgK
	   온도 = 켈빈 온도
	   물의 밀도 = 1000 kg / m^3
	*/
	air_dens = calc_pneumatic_density(temper, press);
	printf("temper = %f, press = %f, air_dens = %f\n", temper, press, air_dens);

	/* 0.5 L 페트병에 0.24 ~ 0.26 L 의 물과 0.24 ~ 0.26 L 의 공기를 구성한다.
	   이때 공기를 6 기압으로 압축했다고 가정하고 문제를 해석해보도록 한다.
	   v_E(t) = sqrt([2 * (p(t) - p_0)]/ρ_Water) 를 보면
	   우리의 경우 위의 press 를 기압으로 활용하면 된다.
	   그리고 대기압은 1 로 물의 밀도와 함께 수식을 계산하면 된다. */
	water_exhaust_vel = calc_exhaust_velocity(press);
	printf("temper = %f, press = %f, water_exhaust_vel = %f\n", temper, press, water_exhaust_vel);

	/* 비열비를 구하지만 Saturation 정보이므로 잘못됨 */
#if 0
	sat_sh_ratio = get_sat_shr_with_convert_unit(press);
	printf("Gamma(specific heat ratio) = %f\n", sat_sh_ratio);
#endif

	return 0;
}
