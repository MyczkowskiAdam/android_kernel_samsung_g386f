/*
 * pmic.h  --  Power Managment Driver for Dialog D2153 PMIC
 *
 * Copyright 2012 Dialog Semiconductor Ltd.
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#ifndef __LINUX_LEOPARD_PMIC_H
#define __LINUX_LEOPARD_PMIC_H

#include <linux/platform_device.h>
#include <linux/regulator/machine.h>
#include <linux/regulator/driver.h>

#define EMULATE_DIALOG_HARDWARE 2153

/*
 * Register values.
 */

enum d2153_regulator_id {
/*
 * DC-DC's
 */
    D2153_BUCK_1 = 0,
    D2153_BUCK_2,
    D2153_BUCK_3,
    D2153_BUCK_4,
    D2153_BUCK_5,
    D2153_BUCK_6,
/*
 * LDOs
 */
    D2153_LDO_1,
    D2153_LDO_2,
    D2153_LDO_3,
    D2153_LDO_4,
    D2153_LDO_5,
    D2153_LDO_6,
    D2153_LDO_7,
    D2153_LDO_8,
    D2153_LDO_9,
    D2153_LDO_10,
    
    D2153_LDO_11,
    D2153_LDO_12,
    D2153_LDO_13,
    D2153_LDO_14,
    D2153_LDO_15,
    D2153_LDO_16,
    D2153_LDO_17,
    D2153_LDO_18,
    D2153_LDO_19,
    D2153_LDO_20,
    D2153_LDO_AUD1,
    D2153_LDO_AUD2,

    D2153_NUMBER_OF_REGULATORS  /* 25 */
};

#define D2153_BUCK1_VOLT_LOWER 600000
#define D2153_BUCK1_VOLT_UPPER 1400000
#define D2153_BUCK1_VOLT_WIDTH 6250
#define D2153_BUCK2_VOLT_LOWER 725000
#define D2153_BUCK2_VOLT_UPPER 2075000
#define D2153_BUCK2_VOLT_WIDTH 25000
#define D2153_BUCK3_VOLT_LOWER 725000
#define D2153_BUCK3_VOLT_UPPER 2075000
#define D2153_BUCK3_VOLT_WIDTH 25000
#define D2153_BUCK4_VOLT_LOWER 725000
#define D2153_BUCK4_VOLT_UPPER 2075000
#define D2153_BUCK4_VOLT_WIDTH 25000
#define D2153_BUCK5_VOLT_LOWER 725000
#define D2153_BUCK5_VOLT_UPPER 2075000
#define D2153_BUCK5_VOLT_WIDTH 25000
#define D2153_BUCK6_VOLT_LOWER 400000
#define D2153_BUCK6_VOLT_UPPER 3500000
#define D2153_BUCK6_VOLT_WIDTH 0

#define D2153_LDO1_VOLT_LOWER 1000000
#define D2153_LDO1_VOLT_UPPER 3100000
#define D2153_LDO1_VOLT_WIDTH 50000
#define D2153_LDO2_VOLT_LOWER 1000000
#define D2153_LDO2_VOLT_UPPER 3100000
#define D2153_LDO2_VOLT_WIDTH 50000
#define D2153_LDO3_VOLT_LOWER 1200000
#define D2153_LDO3_VOLT_UPPER 3000000
#define D2153_LDO3_VOLT_WIDTH 50000
#define D2153_LDO4_VOLT_LOWER 1200000
#define D2153_LDO4_VOLT_UPPER 3300000
#define D2153_LDO4_VOLT_WIDTH 50000
#define D2153_LDO5_VOLT_LOWER 1200000
#define D2153_LDO5_VOLT_UPPER 3300000
#define D2153_LDO5_VOLT_WIDTH 50000
#define D2153_LDO6_VOLT_LOWER 1200000
#define D2153_LDO6_VOLT_UPPER 3300000
#define D2153_LDO6_VOLT_WIDTH 50000
#define D2153_LDO7_VOLT_LOWER 1200000
#define D2153_LDO7_VOLT_UPPER 3300000
#define D2153_LDO7_VOLT_WIDTH 50000
#define D2153_LDO8_VOLT_LOWER 1200000
#define D2153_LDO8_VOLT_UPPER 3300000
#define D2153_LDO8_VOLT_WIDTH 50000
#define D2153_LDO9_VOLT_LOWER 1200000
#define D2153_LDO9_VOLT_UPPER 3300000
#define D2153_LDO9_VOLT_WIDTH 50000
#define D2153_LDO10_VOLT_LOWER 1200000
#define D2153_LDO10_VOLT_UPPER 3300000
#define D2153_LDO10_VOLT_WIDTH 50000
#define D2153_LDO11_VOLT_LOWER 1200000
#define D2153_LDO11_VOLT_UPPER 3300000
#define D2153_LDO11_VOLT_WIDTH 50000
#define D2153_LDO12_VOLT_LOWER 1200000
#define D2153_LDO12_VOLT_UPPER 3300000
#define D2153_LDO12_VOLT_WIDTH 50000
#define D2153_LDO13_VOLT_LOWER 1200000
#define D2153_LDO13_VOLT_UPPER 3300000
#define D2153_LDO13_VOLT_WIDTH 50000
#define D2153_LDO14_VOLT_LOWER 1200000
#define D2153_LDO14_VOLT_UPPER 3300000
#define D2153_LDO14_VOLT_WIDTH 50000
#define D2153_LDO15_VOLT_LOWER 1200000
#define D2153_LDO15_VOLT_UPPER 3300000
#define D2153_LDO15_VOLT_WIDTH 50000
#define D2153_LDO16_VOLT_LOWER 1200000
#define D2153_LDO16_VOLT_UPPER 3300000
#define D2153_LDO16_VOLT_WIDTH 50000
#define D2153_LDO17_VOLT_LOWER 1200000
#define D2153_LDO17_VOLT_UPPER 3300000
#define D2153_LDO17_VOLT_WIDTH 50000
#define D2153_LDO18_VOLT_LOWER 1200000
#define D2153_LDO18_VOLT_UPPER 3300000
#define D2153_LDO18_VOLT_WIDTH 50000
#define D2153_LDO19_VOLT_LOWER 1200000
#define D2153_LDO19_VOLT_UPPER 3300000
#define D2153_LDO19_VOLT_WIDTH 50000
#define D2153_LDO20_VOLT_LOWER 1200000
#define D2153_LDO20_VOLT_UPPER 3300000
#define D2153_LDO20_VOLT_WIDTH 50000
#define D2153_LDOAUD1_VOLT_LOWER 1200000
#define D2153_LDOAUD1_VOLT_UPPER 3300000
#define D2153_LDOAUD1_VOLT_WIDTH 50000
#define D2153_LDOAUD2_VOLT_LOWER 1200000
#define D2153_LDOAUD2_VOLT_UPPER 3300000
#define D2153_LDOAUD2_VOLT_WIDTH 50000

//TODO MW: Check Modes when final design is ready
/* Global MCTL state controled by HW (M_CTL1 and M_CTL2 signals) */
enum d2153_mode_control {
    MCTL_0, /* M_CTL1 = 0, M_CTL2 = 0 */
    MCTL_1, /* M_CTL1 = 0, M_CTL2 = 1 */
    MCTL_2, /* M_CTL1 = 1, M_CTL2 = 0 */
    MCTL_3, /* M_CTL1 = 1, M_CTL2 = 1 */
};

/*regualtor DSM settings */
enum d2153_mode_in_dsm {
    D2153_REGULATOR_LPM_IN_DSM = 0,  /* LPM in DSM(deep sleep mode) */
    D2153_REGULATOR_OFF_IN_DSM,      /* OFF in DSM */
    D2153_REGULATOR_ON_IN_DSM,       /* LPM in DSM */
    D2153_REGULATOR_MAX,
};

/* TODO MW: move those to d2153_reg.h - this are bimask specific to registers' map */
/* CONF and EN is same for all */
//#define D2153_REGULATOR_CONF            (1<<7)
//#define D2153_REGULATOR_EN              (1<<6)

/* TODO MW: description*/
#define D2153_REGULATOR_MCTL3           (3<<6)
#define D2153_REGULATOR_MCTL2           (3<<4)
#define D2153_REGULATOR_MCTL1           (3<<2)
#define D2153_REGULATOR_MCTL0           (3<<0)

/* TODO MW:  figure out more descriptive names to distinguish between global M_CTLx state
 * determined by hardware, and the mode for each regulator configured in BUCKx/LDOx_MCTLy register */

/* MCTL values for regulator bits ... TODO finish description */
#define REGULATOR_MCTL_OFF              0
#define REGULATOR_MCTL_ON               1
#define REGULATOR_MCTL_SLEEP            2
#define REGULATOR_MCTL_TURBO            3 /* Available only for BUCK1 */

#define D2153_REG_MCTL3_SHIFT                     6 /* Bits [7:6] in BUCKx/LDOx_MCTLy register */
#define D2153_REG_MCTL2_SHIFT                     4 /* Bits [5:4] in BUCKx/LDOx_MCTLy register */
#define D2153_REG_MCTL1_SHIFT                     2 /* Bits [3:2] in BUCKx/LDOx_MCTLy register */
#define D2153_REG_MCTL0_SHIFT                     0 /* Bits [1:0] in BUCKx/LDOx_MCTLy register */

/* When M_CTL1 = 1, M_CTL2 = 1 (M_CTL3: global Turbo Mode), regultor is: */
#define D2153_REGULATOR_MCTL3_OFF       (REGULATOR_MCTL_OFF     << D2153_REG_MCTL3_SHIFT)
#define D2153_REGULATOR_MCTL3_ON        (REGULATOR_MCTL_ON      << D2153_REG_MCTL3_SHIFT)
#define D2153_REGULATOR_MCTL3_SLEEP     (REGULATOR_MCTL_SLEEP   << D2153_REG_MCTL3_SHIFT)
#define D2153_REGULATOR_MCTL3_TURBO     (REGULATOR_MCTL_TURBO   << D2153_REG_MCTL3_SHIFT)

/* When M_CTL1 = 1, M_CTL2 = 0 (M_CTL2: TBD: To Be Defined Mode), regulator is: */ //TODO MW: change name when mode defined
#define D2153_REGULATOR_MCTL2_OFF       (REGULATOR_MCTL_OFF     << D2153_REG_MCTL2_SHIFT)
#define D2153_REGULATOR_MCTL2_ON        (REGULATOR_MCTL_ON      << D2153_REG_MCTL2_SHIFT)
#define D2153_REGULATOR_MCTL2_SLEEP     (REGULATOR_MCTL_SLEEP   << D2153_REG_MCTL2_SHIFT)
#define D2153_REGULATOR_MCTL2_TURBO     (REGULATOR_MCTL_TURBO   << D2153_REG_MCTL2_SHIFT)

/* When M_CTL1 = 0, M_CTL2 = 1 (M_CTL1: Normal Mode), regulator is: */
#define D2153_REGULATOR_MCTL1_OFF       (REGULATOR_MCTL_OFF     << D2153_REG_MCTL1_SHIFT)
#define D2153_REGULATOR_MCTL1_ON        (REGULATOR_MCTL_ON      << D2153_REG_MCTL1_SHIFT)
#define D2153_REGULATOR_MCTL1_SLEEP     (REGULATOR_MCTL_SLEEP   << D2153_REG_MCTL1_SHIFT)
#define D2153_REGULATOR_MCTL1_TURBO     (REGULATOR_MCTL_TURBO   << D2153_REG_MCTL1_SHIFT)

/* When M_CTL1 = 0, M_CTL2 = 0 (M_CTL0: Sleep Mode), regulator is: */
#define D2153_REGULATOR_MCTL0_OFF       (REGULATOR_MCTL_OFF     << D2153_REG_MCTL0_SHIFT)
#define D2153_REGULATOR_MCTL0_ON        (REGULATOR_MCTL_ON      << D2153_REG_MCTL0_SHIFT)
#define D2153_REGULATOR_MCTL0_SLEEP     (REGULATOR_MCTL_SLEEP   << D2153_REG_MCTL0_SHIFT)
#define D2153_REGULATOR_MCTL0_TURBO     (REGULATOR_MCTL_TURBO   << D2153_REG_MCTL0_SHIFT)


struct d2153;
struct platform_device;
struct regulator_init_data;


struct d2153_pmic {
    /* Number of regulators of each type on this device */
    //DLG eric. int max_dcdc;

    /* regulator devices */
    struct platform_device *pdev[D2153_NUMBER_OF_REGULATORS];
};

int d2153_platform_regulator_init(struct d2153 *d2153);

#endif  /* __LINUX_LEOPARD_PMIC_H */

