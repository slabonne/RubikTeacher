/*
 * Rubik Teacher
 * Copyright (C) 2026 Sébastien LABONNE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "resolution.h"

#include <QProgressBar>


unsigned char cube_Step0_empty[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0};
unsigned char cube_Step1_Croix1[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,3,3,0,0,0,0,0,4,0,4,4,4,0,4,0,0,0,0,0,5,0,0,5,0,0,0,0,0,6,6,0,0,0};
unsigned char cube_Step2_F2L[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,2,2,2,2,2,2,0,0,0,3,3,0,3,3,0,3,3,0,4,4,4,4,4,4,4,4,4,0,0,0,5,5,5,5,5,5,0,6,6,0,6,6,0,6,6};
unsigned char cube_Step3_OLL[CUBE_SIZE] = {1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,0,0,0,3,3,0,3,3,0,3,3,0,4,4,4,4,4,4,4,4,4,0,0,0,5,5,5,5,5,5,0,6,6,0,6,6,0,6,6};
unsigned char cube_Step4_PLL[CUBE_SIZE] = {1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6};


///////////////////////////////////
// First Croix
////////////////////////////////////

unsigned char FirstCroix1_01[CUBE_SIZE] = {0,0,0,0,4,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,1,0,0,0,0,0,5,0,0,5,0,0,0,0,0,0,0,0,3,0,0,0,0};
unsigned char FirstCroix1_01_alg[] = {F, F};
std::vector<unsigned char> FirstCroix1_01_algo(FirstCroix1_01_alg, FirstCroix1_01_alg + sizeof(FirstCroix1_01_alg) / sizeof(unsigned char));


unsigned char FirstCroix1_02[54] = {0,0,0,0,4,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,5,1,0,0,0,0,0,0,0,3,0,0,5,0};
unsigned char FirstCroix1_02_alg[] = {D, R_, D_};
std::vector<unsigned char> FirstCroix1_02_algo(FirstCroix1_02_alg, FirstCroix1_02_alg + sizeof(FirstCroix1_02_alg) / sizeof(unsigned char));





///////////////////////////////////
// F2L
////////////////////////////////////
unsigned char F2L_00[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,5,5,0,5,5,0,0,0,0,3,3,0,3,3};
unsigned char F2L_00_alg[] = {};
std::vector<unsigned char> F2L_00_algo(F2L_00_alg, F2L_00_alg + sizeof(F2L_00_alg) / sizeof(unsigned char));

unsigned char F2L_01[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,5,3,0,5,5,0,0,0,0,3,3,0,5,3};
unsigned char F2L_01_alg[] = {F_, U, F_, U, U, R_, F, F, R, U, U, F, F};
std::vector<unsigned char> F2L_01_algo(F2L_01_alg, F2L_01_alg + sizeof(F2L_01_alg) / sizeof(unsigned char));

unsigned char F2L_02[CUBE_SIZE] = {0,0,0,3,4,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,5,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,5,0,0,5,5,0,0,0,0,3,3,0,0,3};
unsigned char F2L_02_alg[] = {R, U_, R_, U_, F_, U, F};
std::vector<unsigned char> F2L_02_algo(F2L_02_alg, F2L_02_alg + sizeof(F2L_02_alg) / sizeof(unsigned char));

unsigned char F2L_03[CUBE_SIZE] = {0,5,0,0,4,0,0,0,0,0,2,0,0,2,0,0,3,0,0,0,0,6,6,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,5,0,0,5,5,0,0,0,0,3,3,0,0,3};
unsigned char F2L_03_alg[] = {F_, U, F, U, R, U_, R_};
std::vector<unsigned char> F2L_03_algo(F2L_03_alg, F2L_03_alg + sizeof(F2L_03_alg) / sizeof(unsigned char));

unsigned char F2L_04[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,3,1,1,1,0,1,0,0,0,0,0,5,5,0,5,1,0,0,0,0,3,3,0,3,5};
unsigned char F2L_04_alg[] = {R, R, U, U, R_, U_, R, U_, R_, U, U, R_};
std::vector<unsigned char> F2L_04_algo(F2L_04_alg, F2L_04_alg + sizeof(F2L_04_alg) / sizeof(unsigned char));

unsigned char F2L_05[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,3,1,1,1,0,1,0,0,0,0,0,5,3,0,5,1,0,0,0,0,3,3,0,5,5};
unsigned char F2L_05_alg[] = {F, F, L_, U_, L, U, F, U_, F};
std::vector<unsigned char> F2L_05_algo(F2L_05_alg, F2L_05_alg + sizeof(F2L_05_alg) / sizeof(unsigned char));

unsigned char F2L_06[CUBE_SIZE] = {0,0,0,0,4,5,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,3,1,1,1,0,1,0,0,0,0,0,5,0,0,5,1,0,0,0,3,3,3,0,0,5};
unsigned char F2L_06_alg[] = {R, U_, R, R, F, R, F_};
std::vector<unsigned char> F2L_06_algo(F2L_06_alg, F2L_06_alg + sizeof(F2L_06_alg) / sizeof(unsigned char));

unsigned char F2L_07[CUBE_SIZE] = {0,0,0,0,4,0,0,3,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,3,1,1,1,0,1,0,0,5,0,0,5,0,0,5,1,0,0,0,0,3,3,0,0,5};
unsigned char F2L_07_alg[] = {F_, U_, F, U, F_, U_, F};
std::vector<unsigned char> F2L_07_algo(F2L_07_alg, F2L_07_alg + sizeof(F2L_07_alg) / sizeof(unsigned char));

unsigned char F2L_08[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,5,1,1,1,0,1,0,0,0,0,0,5,5,0,5,3,0,0,0,0,3,3,0,3,1};
unsigned char F2L_08_alg[] = {F, F, U, U, F, U, F_, U, F, U, U, F};
std::vector<unsigned char> F2L_08_algo(F2L_08_alg, F2L_08_alg + sizeof(F2L_08_alg) / sizeof(unsigned char));

unsigned char F2L_09[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,5,1,1,1,0,1,0,0,0,0,0,5,3,0,5,3,0,0,0,0,3,3,0,5,1};
unsigned char F2L_09_alg[] = {R, R, B, U, B_, U_, R_, U, R_};
std::vector<unsigned char> F2L_09_algo(F2L_09_alg, F2L_09_alg + sizeof(F2L_09_alg) / sizeof(unsigned char));

unsigned char F2L_10[CUBE_SIZE] = {0,0,0,0,4,0,0,3,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,5,1,1,1,0,1,0,0,5,0,0,5,0,0,5,3,0,0,0,0,3,3,0,0,1};
unsigned char F2L_10_alg[] = {R, U, U, R_, F_, U, U, F};
std::vector<unsigned char> F2L_10_algo(F2L_10_alg, F2L_10_alg + sizeof(F2L_10_alg) / sizeof(unsigned char));

unsigned char F2L_11[CUBE_SIZE] = {0,0,0,0,4,0,0,5,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,5,1,1,1,0,1,0,0,3,0,0,5,0,0,5,3,0,0,0,0,3,3,0,0,1};
unsigned char F2L_11_alg[] = {U, F_, U, F, R, U, R_};
std::vector<unsigned char> F2L_11_algo(F2L_11_alg, F2L_11_alg + sizeof(F2L_11_alg) / sizeof(unsigned char));

unsigned char F2L_12[CUBE_SIZE] = {0,0,0,0,4,0,0,0,3,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,5,0,5,0,0,0,0,0,3,3,1,3,0};
unsigned char F2L_12_alg[] = {U, R, U, U, B, U, U, B_, R_};
std::vector<unsigned char> F2L_12_algo(F2L_12_alg, F2L_12_alg + sizeof(F2L_12_alg) / sizeof(unsigned char));

unsigned char F2L_13[CUBE_SIZE] = {0,0,0,0,4,0,0,0,3,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,3,0,5,0,0,0,0,0,3,3,1,5,0};
unsigned char F2L_13_alg[] = {U, F_, U_, F, U_, R, U, R_};
std::vector<unsigned char> F2L_13_algo(F2L_13_alg, F2L_13_alg + sizeof(F2L_13_alg) / sizeof(unsigned char));

unsigned char F2L_14[CUBE_SIZE] = {0,0,0,0,4,0,0,3,3,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,5,5,0,5,0,0,5,0,0,0,0,0,3,3,1,0,0};
unsigned char F2L_14_alg[] = {U_, F_, U, F};
std::vector<unsigned char> F2L_14_algo(F2L_14_alg, F2L_14_alg + sizeof(F2L_14_alg) / sizeof(unsigned char));

unsigned char F2L_15[CUBE_SIZE] = {0,0,0,0,4,0,0,5,3,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,3,5,0,5,0,0,5,0,0,0,0,0,3,3,1,0,0};
unsigned char F2L_15_alg[] = {R_, U, U, R, R, U, R, R, U, R};
std::vector<unsigned char> F2L_15_algo(F2L_15_alg, F2L_15_alg + sizeof(F2L_15_alg) / sizeof(unsigned char));

unsigned char F2L_16[CUBE_SIZE] = {0,0,0,3,4,0,0,0,3,0,2,0,0,2,0,0,0,0,0,0,0,6,6,5,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,0,0,5,0,0,0,0,0,3,3,1,0,0};
unsigned char F2L_16_alg[] = {R, R, B, U, B_, U_, R, R};
std::vector<unsigned char> F2L_16_algo(F2L_16_alg, F2L_16_alg + sizeof(F2L_16_alg) / sizeof(unsigned char));

unsigned char F2L_17[CUBE_SIZE] = {0,0,0,5,4,0,0,0,3,0,2,0,0,2,0,0,0,0,0,0,0,6,6,3,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,0,0,5,0,0,0,0,0,3,3,1,0,0};
unsigned char F2L_17_alg[] = {F, F, U_, L_, U, L, F, F};
std::vector<unsigned char> F2L_17_algo(F2L_17_alg, F2L_17_alg + sizeof(F2L_17_alg) / sizeof(unsigned char));

unsigned char F2L_18[CUBE_SIZE] = {0,5,0,0,4,0,0,0,3,0,2,0,0,2,0,0,3,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,0,0,5,0,0,0,0,0,3,3,1,0,0};
unsigned char F2L_18_alg[] = {R, U, R_};
std::vector<unsigned char> F2L_18_algo(F2L_18_alg, F2L_18_alg + sizeof(F2L_18_alg) / sizeof(unsigned char));

unsigned char F2L_19[CUBE_SIZE] = {0,3,0,0,4,0,0,0,3,0,2,0,0,2,0,0,5,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,0,0,5,0,0,0,0,0,3,3,1,0,0};
unsigned char F2L_19_alg[] = {F_, U_, L_, U, U, L, U_, F};
std::vector<unsigned char> F2L_19_algo(F2L_19_alg, F2L_19_alg + sizeof(F2L_19_alg) / sizeof(unsigned char));

unsigned char F2L_20[CUBE_SIZE] = {0,0,0,0,4,5,0,0,3,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,0,0,5,0,0,0,0,3,3,3,1,0,0};
unsigned char F2L_20_alg[] = {U_, R, U_, R_, U, R, U, R_};
std::vector<unsigned char> F2L_20_algo(F2L_20_alg, F2L_20_alg + sizeof(F2L_20_alg) / sizeof(unsigned char));

unsigned char F2L_21[CUBE_SIZE] = {0,0,0,0,4,3,0,0,3,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,0,0,5,0,0,0,0,5,3,3,1,0,0};
unsigned char F2L_21_alg[] = {R, U_, R_, U, U, F_, U_, F};
std::vector<unsigned char> F2L_21_algo(F2L_21_alg, F2L_21_alg + sizeof(F2L_21_alg) / sizeof(unsigned char));

unsigned char F2L_22[CUBE_SIZE] = {0,0,0,0,4,0,0,0,5,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,5,5,0,5,0,0,0,0,0,3,3,3,3,0};
unsigned char F2L_22_alg[] = {U_, F_, U, U, L_, U, U, L, F};
std::vector<unsigned char> F2L_22_algo(F2L_22_alg, F2L_22_alg + sizeof(F2L_22_alg) / sizeof(unsigned char));

unsigned char F2L_23[CUBE_SIZE] = {0,0,0,0,4,0,0,0,5,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,5,3,0,5,0,0,0,0,0,3,3,3,5,0};
unsigned char F2L_23_alg[] = {U_, R, U, R_, U, F_, U_, F};
std::vector<unsigned char> F2L_23_algo(F2L_23_alg, F2L_23_alg + sizeof(F2L_23_alg) / sizeof(unsigned char));

unsigned char F2L_24[CUBE_SIZE] = {0,0,0,0,4,0,0,3,5,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,5,1,0,5,0,0,5,0,0,0,0,0,3,3,3,0,0};
unsigned char F2L_24_alg[] = {U, F_, U, F, U_, F_, U_, F};
std::vector<unsigned char> F2L_24_algo(F2L_24_alg, F2L_24_alg + sizeof(F2L_24_alg) / sizeof(unsigned char));

unsigned char F2L_25[CUBE_SIZE] = {0,0,0,0,4,0,0,5,5,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,3,1,0,5,0,0,5,0,0,0,0,0,3,3,3,0,0};
unsigned char F2L_25_alg[] = {F_, U, F, U, U, R, U, R_};
std::vector<unsigned char> F2L_25_algo(F2L_25_alg, F2L_25_alg + sizeof(F2L_25_alg) / sizeof(unsigned char));

unsigned char F2L_26[CUBE_SIZE] = {0,0,0,3,4,0,0,0,5,0,2,0,0,2,0,0,0,0,0,0,0,6,6,5,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,5,0,0,5,0,0,0,0,0,3,3,3,0,0};
unsigned char F2L_26_alg[] = {F_, U_, F};
std::vector<unsigned char> F2L_26_algo(F2L_26_alg, F2L_26_alg + sizeof(F2L_26_alg) / sizeof(unsigned char));

unsigned char F2L_27[CUBE_SIZE] = {0,0,0,5,4,0,0,0,5,0,2,0,0,2,0,0,0,0,0,0,0,6,6,3,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,5,0,0,5,0,0,0,0,0,3,3,3,0,0};
unsigned char F2L_27_alg[] = {R, U, B, U, U, B_, U, R_};
std::vector<unsigned char> F2L_27_algo(F2L_27_alg, F2L_27_alg + sizeof(F2L_27_alg) / sizeof(unsigned char));

unsigned char F2L_28[CUBE_SIZE] = {0,5,0,0,4,0,0,0,5,0,2,0,0,2,0,0,3,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,5,0,0,5,0,0,0,0,0,3,3,3,0,0};
unsigned char F2L_28_alg[] = {F, F, L_, U_, L, U, F, F};
std::vector<unsigned char> F2L_28_algo(F2L_28_alg, F2L_28_alg + sizeof(F2L_28_alg) / sizeof(unsigned char));

unsigned char F2L_29[CUBE_SIZE] = {0,3,0,0,4,0,0,0,5,0,2,0,0,2,0,0,5,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,5,0,0,5,0,0,0,0,0,3,3,3,0,0};
unsigned char F2L_29_alg[] = {R, R, U, B, U_, B_, R, R};
std::vector<unsigned char> F2L_29_algo(F2L_29_alg, F2L_29_alg + sizeof(F2L_29_alg) / sizeof(unsigned char));

unsigned char F2L_30[CUBE_SIZE] = {0,0,0,0,4,5,0,0,5,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,5,0,0,5,0,0,0,0,3,3,3,3,0,0};
unsigned char F2L_30_alg[] = {U, R, U_, R_};
std::vector<unsigned char> F2L_30_algo(F2L_30_alg, F2L_30_alg + sizeof(F2L_30_alg) / sizeof(unsigned char));

unsigned char F2L_31[CUBE_SIZE] = {0,0,0,0,4,3,0,0,5,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,5,0,0,5,0,0,0,0,5,3,3,3,0,0};
unsigned char F2L_31_alg[] = {F, U, U, F, F, U_, F, F, U_, F_};
std::vector<unsigned char> F2L_31_algo(F2L_31_alg, F2L_31_alg + sizeof(F2L_31_alg) / sizeof(unsigned char));

unsigned char F2L_32[CUBE_SIZE] = {0,0,0,0,4,0,0,0,1,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,0,5,5,0,5,0,0,0,0,0,3,3,5,3,0};
unsigned char F2L_32_alg[] = {R, R, U, R, R, U, R, R, U, U, R, R};
std::vector<unsigned char> F2L_32_algo(F2L_32_alg, F2L_32_alg + sizeof(F2L_32_alg) / sizeof(unsigned char));

unsigned char F2L_33[CUBE_SIZE] = {0,0,0,0,4,0,0,0,1,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,0,5,3,0,5,0,0,0,0,0,3,3,5,5,0};
unsigned char F2L_33_alg[] = {R, U_, R_, F_, U, U, F};
std::vector<unsigned char> F2L_33_algo(F2L_33_alg, F2L_33_alg + sizeof(F2L_33_alg) / sizeof(unsigned char));

unsigned char F2L_34[CUBE_SIZE] = {0,0,0,0,4,0,0,3,1,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,5,3,0,5,0,0,5,0,0,0,0,0,3,3,5,0,0};
unsigned char F2L_34_alg[] = {F_, U, U, F, U, F_, U_, F};
std::vector<unsigned char> F2L_34_algo(F2L_34_alg, F2L_34_alg + sizeof(F2L_34_alg) / sizeof(unsigned char));

unsigned char F2L_35[CUBE_SIZE] = {0,0,0,0,4,0,0,5,1,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,3,3,0,5,0,0,5,0,0,0,0,0,3,3,5,0,0};
unsigned char F2L_35_alg[] = {R, U, R, B_, R_, B, U, U, R_};
std::vector<unsigned char> F2L_35_algo(F2L_35_alg, F2L_35_alg + sizeof(F2L_35_alg) / sizeof(unsigned char));

unsigned char F2L_36[CUBE_SIZE] = {0,0,0,3,4,0,0,0,1,0,2,0,0,2,0,0,0,0,0,0,0,6,6,5,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,0,5,0,0,5,0,0,0,0,0,3,3,5,0,0};
unsigned char F2L_36_alg[] = {U_, F_, U, U, F, F, R_, F_, R};
std::vector<unsigned char> F2L_36_algo(F2L_36_alg, F2L_36_alg + sizeof(F2L_36_alg) / sizeof(unsigned char));

unsigned char F2L_37[CUBE_SIZE] = {0,0,0,5,4,0,0,0,1,0,2,0,0,2,0,0,0,0,0,0,0,6,6,3,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,0,5,0,0,5,0,0,0,0,0,3,3,5,0,0};
unsigned char F2L_37_alg[] = {R, B, U, U, B_, R_};
std::vector<unsigned char> F2L_37_algo(F2L_37_alg, F2L_37_alg + sizeof(F2L_37_alg) / sizeof(unsigned char));

unsigned char F2L_38[CUBE_SIZE] = {0,5,0,0,4,0,0,0,1,0,2,0,0,2,0,0,3,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,0,5,0,0,5,0,0,0,0,0,3,3,5,0,0};
unsigned char F2L_38_alg[] = {U,R,U,U,R,R,F,R,F_};
std::vector<unsigned char> F2L_38_algo(F2L_38_alg, F2L_38_alg + sizeof(F2L_38_alg) / sizeof(unsigned char));

unsigned char F2L_39[CUBE_SIZE] = {0,3,0,0,4,0,0,0,1,0,2,0,0,2,0,0,5,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,0,5,0,0,5,0,0,0,0,0,3,3,5,0,0};
unsigned char F2L_39_alg[] = {F_,L_,U,U,L,F};
std::vector<unsigned char> F2L_39_algo(F2L_39_alg, F2L_39_alg + sizeof(F2L_39_alg) / sizeof(unsigned char));

unsigned char F2L_40[CUBE_SIZE] = {0,0,0,0,4,5,0,0,1,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,0,5,0,0,5,0,0,0,0,3,3,3,5,0,0};
unsigned char F2L_40_alg[] = {R,U,U,R_,U_,R,U,R_};
std::vector<unsigned char> F2L_40_algo(F2L_40_alg, F2L_40_alg + sizeof(F2L_40_alg) / sizeof(unsigned char));

unsigned char F2L_41[CUBE_SIZE] = {0,0,0,0,4,3,0,0,1,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,3,0,5,0,0,5,0,0,0,0,5,3,3,5,0,0};
unsigned char F2L_41_alg[] = {U,U,F,F,U,U,F,U,F_,U,F,F};
std::vector<unsigned char> F2L_41_algo(F2L_41_alg, F2L_41_alg + sizeof(F2L_41_alg) / sizeof(unsigned char));


///////////////////////////////////
// F2L Multislotting
////////////////////////////////////
unsigned char F2L_Multislot_01[CUBE_SIZE] = {0,5,0,0,4,0,0,5,3,0,2,0,0,2,0,0,3,0,0,0,0,6,6,0,0,0,0,0,1,6,1,1,1,0,1,0,0,6,5,0,5,0,0,5,5,0,0,0,0,3,3,1,0,1};
unsigned char F2L_Multislot_01_alg[] = {L_, R, U, R_, L};
std::vector<unsigned char> F2L_Multislot_01_algo(F2L_Multislot_01_alg, F2L_Multislot_01_alg + sizeof(F2L_Multislot_01_alg) / sizeof(unsigned char));

unsigned char F2L_Multislot_02[CUBE_SIZE] = {6,5,0,0,4,5,0,0,3,0,2,0,0,2,0,1,3,0,0,0,5,6,6,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,5,0,5,0,0,5,0,0,0,0,6,3,3,1,0,0};
unsigned char F2L_Multislot_02_alg[] = {L_, R, U, R_, L, U_, L_, U_, L};
std::vector<unsigned char> F2L_Multislot_02_algo(F2L_Multislot_02_alg, F2L_Multislot_02_alg + sizeof(F2L_Multislot_02_alg) / sizeof(unsigned char));

unsigned char F2L_Multislot_03[CUBE_SIZE] = {0,5,0,0,4,0,1,0,3,0,2,0,0,2,0,0,3,0,0,0,0,6,6,0,0,0,5,0,1,0,1,1,1,0,1,0,6,0,5,0,5,5,0,5,0,0,0,0,0,3,3,1,6,0};
unsigned char F2L_Multislot_03_alg[] = {L_, R, U, R_, U, L};
std::vector<unsigned char> F2L_Multislot_03_algo(F2L_Multislot_03_alg, F2L_Multislot_03_alg + sizeof(F2L_Multislot_03_alg) / sizeof(unsigned char));

unsigned char F2L_Multislot_04[CUBE_SIZE] = {0,5,0,5,4,0,0,0,3,0,2,0,0,2,0,0,3,0,0,0,0,6,6,6,5,0,0,6,1,0,1,1,1,0,1,0,0,0,5,0,5,0,1,5,0,0,0,0,0,3,3,1,0,0};
unsigned char F2L_Multislot_04_alg[] = {L_, R, U, R_, L, L, F_, L_, F};
std::vector<unsigned char> F2L_Multislot_04_algo(F2L_Multislot_04_alg, F2L_Multislot_04_alg + sizeof(F2L_Multislot_04_alg) / sizeof(unsigned char));

unsigned char F2L_Multislot_05[CUBE_SIZE] = {5,5,0,0,4,0,0,0,3,0,2,0,0,2,0,6,3,0,0,0,1,6,6,0,0,6,0,0,1,0,1,1,1,0,1,0,0,0,5,5,5,0,0,5,0,0,0,0,0,3,3,1,0,0};
unsigned char F2L_Multislot_05_alg[] = {L_, R, U, R_, L, U, L_, U, U, L};
std::vector<unsigned char> F2L_Multislot_05_algo(F2L_Multislot_05_alg, F2L_Multislot_05_alg + sizeof(F2L_Multislot_05_alg) / sizeof(unsigned char));




///////////////////////////////////
// OLL
////////////////////////////////////

unsigned char OLL_00[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,0,0,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_00_alg[] = {};
std::vector<unsigned char> OLL_00_algo(OLL_00_alg, OLL_00_alg + sizeof(OLL_00_alg) / sizeof(unsigned char));

unsigned char OLL_01[CUBE_SIZE] = {0,4,0,4,4,4,4,4,0,2,2,2,2,2,2,4,0,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,0,4,5,5,5,5,5,5,4,3,3,0,3,3,0,3,3};
unsigned char OLL_01_alg[] = {R, U_, L_, U, R_, U_, L};
std::vector<unsigned char> OLL_01_algo(OLL_01_alg, OLL_01_alg + sizeof(OLL_01_alg) / sizeof(unsigned char));

unsigned char OLL_02[CUBE_SIZE] = {0,4,0,4,4,4,0,4,4,2,2,2,2,2,2,0,0,4,6,6,4,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,0,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_02_alg[] = {L_, U, R, U_, L, U, R_};
std::vector<unsigned char> OLL_02_algo(OLL_02_alg, OLL_02_alg + sizeof(OLL_02_alg) / sizeof(unsigned char));

unsigned char OLL_03[CUBE_SIZE] = {4,4,4,4,4,4,0,4,0,2,2,2,2,2,2,0,0,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,0,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_03_alg[] = {L, L, D_, L, U, U, L_, D, L, U, U, L};
std::vector<unsigned char> OLL_03_algo(OLL_03_alg, OLL_03_alg + sizeof(OLL_03_alg) / sizeof(unsigned char));

unsigned char OLL_04[CUBE_SIZE] = {4,4,0,4,4,4,4,4,0,2,2,2,2,2,2,0,0,4,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,0,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_04_alg[] = {R_, F_, L, F, R, F_, L_, F};
std::vector<unsigned char> OLL_04_algo(OLL_04_alg, OLL_04_alg + sizeof(OLL_04_alg) / sizeof(unsigned char));

unsigned char OLL_05[CUBE_SIZE] = {4,4,0,4,4,4,0,4,4,2,2,2,2,2,2,0,0,4,6,6,0,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_05_alg[] = {R_, F_, L_, F, R, RZ_, R_, F, R};
std::vector<unsigned char> OLL_05_algo(OLL_05_alg, OLL_05_alg + sizeof(OLL_05_alg) / sizeof(unsigned char));

unsigned char OLL_06[CUBE_SIZE] = {0,4,0,4,4,4,0,4,0,2,2,2,2,2,2,0,0,4,6,6,4,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,0,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_06_alg[] = {R, U_, U_, R, R, U_, R, R, U_, R, R, U_, U_, R};
std::vector<unsigned char> OLL_06_algo(OLL_06_alg, OLL_06_alg + sizeof(OLL_06_alg) / sizeof(unsigned char));

unsigned char OLL_07[CUBE_SIZE] = {0,4,0,4,4,4,0,4,0,2,2,2,2,2,2,4,0,4,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,0,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_07_alg[] = {R, U_, U_, R_, U_, R, U, R_, U_, R, U_, R_};
std::vector<unsigned char> OLL_07_algo(OLL_07_alg, OLL_07_alg + sizeof(OLL_07_alg) / sizeof(unsigned char));

unsigned char OLL_08[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,2,2,2,2,2,2,0,4,0,6,6,4,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,4,3,3,4,3,3,4,3,3};
unsigned char OLL_08_alg[] = {R,U,B_,l,U,l,l,RX_,U_,R_,F,R,F_};
std::vector<unsigned char> OLL_08_algo(OLL_08_alg, OLL_08_alg + sizeof(OLL_08_alg) / sizeof(unsigned char));

unsigned char OLL_09[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,2,2,2,2,2,2,0,4,0,6,6,4,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,4,4,5,5,5,5,5,5,4,3,3,4,3,3,0,3,3};
unsigned char OLL_09_alg[] = {R_,F,R,F_,U,U,R_,F,R,RZ_,R,R,U,U,R};
std::vector<unsigned char> OLL_09_algo(OLL_09_alg, OLL_09_alg + sizeof(OLL_09_alg) / sizeof(unsigned char));

unsigned char OLL_10[CUBE_SIZE] = {0,0,0,0,4,0,0,0,4,2,2,2,2,2,2,4,4,0,6,6,0,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,4,3,3,4,3,3,0,3,3};
unsigned char OLL_10_alg[] = {RZ,L_,R,R,B,R_,B,L,U_,U_,L_,B,MX, RX_};
std::vector<unsigned char> OLL_10_algo(OLL_10_alg, OLL_10_alg + sizeof(OLL_10_alg) / sizeof(unsigned char));

unsigned char OLL_11[CUBE_SIZE] = {0,0,4,0,4,0,0,0,0,2,2,2,2,2,2,0,4,0,6,6,4,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,4,0,5,5,5,5,5,5,0,3,3,4,3,3,4,3,3};
unsigned char OLL_11_alg[] = {R_,U,U,RX,R_,U,R,U_,RZ,R_,U_,R_,U,R_,F, RX_, RY_};
std::vector<unsigned char> OLL_11_algo(OLL_11_alg, OLL_11_alg + sizeof(OLL_11_alg) / sizeof(unsigned char));

unsigned char OLL_12[CUBE_SIZE] = {4,0,4,0,4,0,0,0,0,2,2,2,2,2,2,0,4,0,6,6,0,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,4,3,3,4,3,3};
unsigned char OLL_12_alg[] = {R_,U,U,F,R,U,R_,U_,RZ_,R,R,U,U,RX_,R,U,RX};
std::vector<unsigned char> OLL_12_algo(OLL_12_alg, OLL_12_alg + sizeof(OLL_12_alg) / sizeof(unsigned char));

unsigned char OLL_13[CUBE_SIZE] = {0,0,0,0,4,0,4,0,4,2,2,2,2,2,2,4,4,4,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_13_alg[] = {F,R,U,R_,U,RZ_,R_,U,U,RX,R_,U,R,U_,RX_};
std::vector<unsigned char> OLL_13_algo(OLL_13_alg, OLL_13_alg + sizeof(OLL_13_alg) / sizeof(unsigned char));

unsigned char OLL_14[CUBE_SIZE] = {4,0,0,0,4,0,0,0,4,2,2,2,2,2,2,0,4,4,6,6,0,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_14_alg[] = {R,U,R_,U,R_,F,R,F_,U,U,R_,F,R,F_};
std::vector<unsigned char> OLL_14_algo(OLL_14_alg, OLL_14_alg + sizeof(OLL_14_alg) / sizeof(unsigned char));

unsigned char OLL_15[CUBE_SIZE] = {4,0,4,0,4,0,4,0,4,2,2,2,2,2,2,0,4,0,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_15_alg[] = {MX,U,U,MX_,U,U,MX,U,MX_,U,U,MX,U,U,MX_};
std::vector<unsigned char> OLL_15_algo(OLL_15_alg, OLL_15_alg + sizeof(OLL_15_alg) / sizeof(unsigned char));

unsigned char OLL_16[CUBE_SIZE] = {0,0,4,4,4,4,0,0,4,2,2,2,2,2,2,0,4,0,6,6,4,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_16_alg[] = {F,R,U,R_,U_,F_};
std::vector<unsigned char> OLL_16_algo(OLL_16_alg, OLL_16_alg + sizeof(OLL_16_alg) / sizeof(unsigned char));

unsigned char OLL_17[CUBE_SIZE] = {0,0,4,4,4,4,0,0,4,2,2,2,2,2,2,4,4,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,4,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_17_alg[] = {R,U,R_,U_,R_,F,R,F_};
std::vector<unsigned char> OLL_17_algo(OLL_17_alg, OLL_17_alg + sizeof(OLL_17_alg) / sizeof(unsigned char));

unsigned char OLL_18[CUBE_SIZE] = {0,4,0,0,4,0,0,4,0,2,2,2,2,2,2,0,0,0,6,6,4,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,4,3,3,4,3,3,4,3,3};
unsigned char OLL_18_alg[] = {R,U_,RZ,R,R,D,R_,U,U,R,D_,R,R,d,R_};
std::vector<unsigned char> OLL_18_algo(OLL_18_alg, OLL_18_alg + sizeof(OLL_18_alg) / sizeof(unsigned char));

unsigned char OLL_19[CUBE_SIZE] = {0,4,0,0,4,0,0,4,0,2,2,2,2,2,2,4,0,0,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,0,0,5,5,5,5,5,5,4,3,3,4,3,3,4,3,3};
unsigned char OLL_19_alg[] = {R_,U_,RZ,L_,U,L_,RZ_,L,F,L_,F,R};
std::vector<unsigned char> OLL_19_algo(OLL_19_alg, OLL_19_alg + sizeof(OLL_19_alg) / sizeof(unsigned char));

unsigned char OLL_20[CUBE_SIZE] = {0,4,0,0,4,0,0,4,0,2,2,2,2,2,2,0,0,0,6,6,4,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,0,4,5,5,5,5,5,5,4,3,3,4,3,3,0,3,3};
unsigned char OLL_20_alg[] = {R_,U_,RZ_,R_,U,R,U_,R_,U,R,RX_,U,RX};
std::vector<unsigned char> OLL_20_algo(OLL_20_alg, OLL_20_alg + sizeof(OLL_20_alg) / sizeof(unsigned char));

unsigned char OLL_21[CUBE_SIZE] = {0,0,0,4,4,4,0,0,0,2,2,2,2,2,2,0,4,0,6,6,4,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,4,3,3,0,3,3,4,3,3};
unsigned char OLL_21_alg[] = {L_,B_,L,U_,R_,U,R,U_,R_,U,R,L_,B,L};
std::vector<unsigned char> OLL_21_algo(OLL_21_alg, OLL_21_alg + sizeof(OLL_21_alg) / sizeof(unsigned char));

unsigned char OLL_22[CUBE_SIZE] = {0,4,4,0,4,4,4,0,0,2,2,2,2,2,2,4,0,0,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,0,3,3,4,3,3};
unsigned char OLL_22_alg[] = {R_,U,U,l,R,U_,R_,U,l_,U,U,R};
std::vector<unsigned char> OLL_22_algo(OLL_22_alg, OLL_22_alg + sizeof(OLL_22_alg) / sizeof(unsigned char));

unsigned char OLL_23[CUBE_SIZE] = {4,0,4,4,4,0,0,4,0,2,2,2,2,2,2,0,4,0,6,6,0,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,0,3,3,4,3,3,4,3,3};
unsigned char OLL_23_alg[] = {RX_,U_,R,U_,R_,R_,F,RX,R,U,R_,U_,R,B,B};
std::vector<unsigned char> OLL_23_algo(OLL_23_alg, OLL_23_alg + sizeof(OLL_23_alg) / sizeof(unsigned char));

unsigned char OLL_24[CUBE_SIZE] = {0,4,0,4,4,0,0,0,4,2,2,2,2,2,2,0,0,4,6,6,4,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,4,0,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_24_alg[] = {R_,U_,R,RZ_,RX_,R,U_,R_,F,R,U,R_,RX};
std::vector<unsigned char> OLL_24_algo(OLL_24_alg, OLL_24_alg + sizeof(OLL_24_alg) / sizeof(unsigned char));

unsigned char OLL_25[CUBE_SIZE] = {0,0,4,4,4,0,0,4,0,2,2,2,2,2,2,4,4,0,6,6,0,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,0,4,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_25_alg[] = {R,U,R_,RZ,R_,F,R,U_,R_,F_,R};
std::vector<unsigned char> OLL_25_algo(OLL_25_alg, OLL_25_alg + sizeof(OLL_25_alg) / sizeof(unsigned char));

unsigned char OLL_26[CUBE_SIZE] = {4,0,4,0,4,4,0,4,0,2,2,2,2,2,2,0,4,0,6,6,0,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,0,3,3,0,3,3,4,3,3};
unsigned char OLL_26_alg[] = {R_,R_,U,R_,B_,R,U_,R_,R_,U,R,B,R_};
std::vector<unsigned char> OLL_26_algo(OLL_26_alg, OLL_26_alg + sizeof(OLL_26_alg) / sizeof(unsigned char));

unsigned char OLL_27[CUBE_SIZE] = {0,0,4,4,4,0,0,4,4,2,2,2,2,2,2,0,4,0,6,6,4,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_27_alg[] = {R,U_,U_,R_,U_,R,U_,R,R,RZ_,R_,U_,R,U,B};
std::vector<unsigned char> OLL_27_algo(OLL_27_alg, OLL_27_alg + sizeof(OLL_27_alg) / sizeof(unsigned char));

unsigned char OLL_28[CUBE_SIZE] = {0,4,0,0,4,4,4,0,4,2,2,2,2,2,2,4,0,4,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_28_alg[] = {U_,R_,U,U,R,U,R_,U,R,R,RZ,R,U,R_,U_,F_};
std::vector<unsigned char> OLL_28_algo(OLL_28_alg, OLL_28_alg + sizeof(OLL_28_alg) / sizeof(unsigned char));

unsigned char OLL_29[CUBE_SIZE] = {0,0,4,4,4,0,4,4,0,2,2,2,2,2,2,4,4,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,0,3,3,4,3,3,4,3,3};
unsigned char OLL_29_alg[] = {RX_,R,U_,R_,U,RZ_,R,U,R_,U_,RY_};
std::vector<unsigned char> OLL_29_algo(OLL_29_alg, OLL_29_alg + sizeof(OLL_29_alg) / sizeof(unsigned char));

unsigned char OLL_30[CUBE_SIZE] = {0,4,0,4,4,0,0,0,0,2,2,2,2,2,2,0,0,4,6,6,4,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,4,4,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_30_alg[] = {F,R,U,R_,U_,R,U,R_,U_,F_};
std::vector<unsigned char> OLL_30_algo(OLL_30_alg, OLL_30_alg + sizeof(OLL_30_alg) / sizeof(unsigned char));

unsigned char OLL_31[CUBE_SIZE] = {0,4,0,0,4,4,0,0,0,2,2,2,2,2,2,4,0,0,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,4,0,5,5,5,5,5,5,4,3,3,0,3,3,4,3,3};
unsigned char OLL_31_alg[] = {F_,L_,U_,L,U,L_,U_,L,U,F};
std::vector<unsigned char> OLL_31_algo(OLL_31_alg, OLL_31_alg + sizeof(OLL_31_alg) / sizeof(unsigned char));

unsigned char OLL_32[CUBE_SIZE] = {0,0,0,0,4,4,0,4,0,2,2,2,2,2,2,0,4,4,6,6,4,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,0,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_32_alg[] = {L,U_,RZ_,R_,U_,U_,R_,U,R,U_,R,U,U,R,d_,L_};
std::vector<unsigned char> OLL_32_algo(OLL_32_alg, OLL_32_alg + sizeof(OLL_32_alg) / sizeof(unsigned char));

unsigned char OLL_33[CUBE_SIZE] = {0,4,0,0,4,4,0,0,0,2,2,2,2,2,2,0,0,4,6,6,4,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,4,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_33_alg[] = {R_,F,R_,F_,R,R,U,U,RX_,U_,R,U,R_,RX};
std::vector<unsigned char> OLL_33_algo(OLL_33_alg, OLL_33_alg + sizeof(OLL_33_alg) / sizeof(unsigned char));

unsigned char OLL_34[CUBE_SIZE] = {0,4,0,0,4,4,0,0,0,2,2,2,2,2,2,4,0,4,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,4,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_34_alg[] = {R_,F,R,F_,U,U,R,R,RZ,R_,F_,R,F_};
std::vector<unsigned char> OLL_34_algo(OLL_34_alg, OLL_34_alg + sizeof(OLL_34_alg) / sizeof(unsigned char));

unsigned char OLL_35[CUBE_SIZE] = {0,4,0,4,4,0,0,0,0,2,2,2,2,2,2,4,0,4,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,4,4,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_35_alg[] = {L,F_,L_,F,U,U,L,L,RZ_,L,F,L_,F};
std::vector<unsigned char> OLL_35_algo(OLL_35_alg, OLL_35_alg + sizeof(OLL_35_alg) / sizeof(unsigned char));

unsigned char OLL_36[CUBE_SIZE] = {4,4,0,4,4,0,4,0,0,2,2,2,2,2,2,0,0,4,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,4,4,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_36_alg[] = {L,d,R_,d_,L_,U,L,F,L_};
std::vector<unsigned char> OLL_36_algo(OLL_36_alg, OLL_36_alg + sizeof(OLL_36_alg) / sizeof(unsigned char));

unsigned char OLL_37[CUBE_SIZE] = {0,4,4,0,4,4,0,0,4,2,2,2,2,2,2,4,0,0,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,4,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_37_alg[] = {R_,d_,L,d,R,U_,R_,F_,R};
std::vector<unsigned char> OLL_37_algo(OLL_37_alg, OLL_37_alg + sizeof(OLL_37_alg) / sizeof(unsigned char));

unsigned char OLL_38[CUBE_SIZE] = {4,4,4,0,4,4,0,0,0,2,2,2,2,2,2,0,0,0,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,4,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_38_alg[] = {L,U,RZ_,R,U_,R_,F_};
std::vector<unsigned char> OLL_38_algo(OLL_38_alg, OLL_38_alg + sizeof(OLL_38_alg) / sizeof(unsigned char));

unsigned char OLL_39[CUBE_SIZE] = {4,4,4,4,4,0,0,0,0,2,2,2,2,2,2,0,0,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,4,4,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_39_alg[] = {R_,U_,RZ,L_,U,L,F};
std::vector<unsigned char> OLL_39_algo(OLL_39_alg, OLL_39_alg + sizeof(OLL_39_alg) / sizeof(unsigned char));

unsigned char OLL_40[CUBE_SIZE] = {0,0,4,0,4,4,4,4,0,2,2,2,2,2,2,0,4,0,6,6,4,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,0,0,4,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_40_alg[] = {L,U,L_,U,L,U_,L_,U_,RZ_,RZ_,R_,F,R,F_};
std::vector<unsigned char> OLL_40_algo(OLL_40_alg, OLL_40_alg + sizeof(OLL_40_alg) / sizeof(unsigned char));

unsigned char OLL_41[CUBE_SIZE] = {4,0,0,4,4,0,0,4,4,2,2,2,2,2,2,0,4,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,0,0,5,5,5,5,5,5,4,3,3,4,3,3,0,3,3};
unsigned char OLL_41_alg[] = {R_,U_,R,U_,R_,U,R,U,RZ,F,R_,F_,R};
std::vector<unsigned char> OLL_41_algo(OLL_41_alg, OLL_41_alg + sizeof(OLL_41_alg) / sizeof(unsigned char));

unsigned char OLL_42[CUBE_SIZE] = {4,0,0,4,4,4,0,0,4,2,2,2,2,2,2,0,4,4,6,6,0,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_42_alg[] = {R_,F,R,U,R_,U_,RZ,L_,d,R};
std::vector<unsigned char> OLL_42_algo(OLL_42_alg, OLL_42_alg + sizeof(OLL_42_alg) / sizeof(unsigned char));

unsigned char OLL_43[CUBE_SIZE] = {0,0,4,4,4,4,4,0,0,2,2,2,2,2,2,4,4,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,0,3,3,4,3,3};
unsigned char OLL_43_alg[] = {L,F_,L_,U_,L,U,RZ_,R,d_,L_};
std::vector<unsigned char> OLL_43_algo(OLL_43_alg, OLL_43_alg + sizeof(OLL_43_alg) / sizeof(unsigned char));

unsigned char OLL_44[CUBE_SIZE] = {0,4,0,4,4,0,4,0,0,2,2,2,2,2,2,4,0,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,4,4,5,5,5,5,5,5,4,3,3,4,3,3,0,3,3};
unsigned char OLL_44_alg[] = {L,F,R_,F,R,F,F,L_};
std::vector<unsigned char> OLL_44_algo(OLL_44_alg, OLL_44_alg + sizeof(OLL_44_alg) / sizeof(unsigned char));

unsigned char OLL_45[CUBE_SIZE] = {4,0,0,4,4,0,0,4,0,2,2,2,2,2,2,0,4,4,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,0,0,5,5,5,5,5,5,0,3,3,4,3,3,4,3,3};
unsigned char OLL_45_alg[] = {L_,B_,L,U_,R_,U,R,L_,B,L};
std::vector<unsigned char> OLL_45_algo(OLL_45_alg, OLL_45_alg + sizeof(OLL_45_alg) / sizeof(unsigned char));

unsigned char OLL_46[CUBE_SIZE] = {4,4,0,0,4,4,0,0,0,2,2,2,2,2,2,0,0,4,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,4,0,5,5,5,5,5,5,0,3,3,0,3,3,4,3,3};
unsigned char OLL_46_alg[] = {r,R_,R_,U_,R,U_,R_,U,U,R,U_,MX_};
std::vector<unsigned char> OLL_46_algo(OLL_46_alg, OLL_46_alg + sizeof(OLL_46_alg) / sizeof(unsigned char));

unsigned char OLL_47[CUBE_SIZE] = {0,4,4,4,4,0,0,0,0,2,2,2,2,2,2,4,0,0,6,6,0,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,4,4,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_47_alg[] = {l_,L,L,U,L_,U,L,U,U,L_,U,MX_};
std::vector<unsigned char> OLL_47_algo(OLL_47_alg, OLL_47_alg + sizeof(OLL_47_alg) / sizeof(unsigned char));

unsigned char OLL_48[CUBE_SIZE] = {4,4,0,0,4,0,4,4,0,2,2,2,2,2,2,0,0,0,6,6,0,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,4,3,3,4,3,3,4,3,3};
unsigned char OLL_48_alg[] = {R,U,RX_,R,U_,R_,U,RX,U_,R_};
std::vector<unsigned char> OLL_48_algo(OLL_48_alg, OLL_48_alg + sizeof(OLL_48_alg) / sizeof(unsigned char));

unsigned char OLL_49[CUBE_SIZE] = {0,0,0,4,4,4,4,0,4,2,2,2,2,2,2,0,4,0,6,6,4,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,4,3,3,0,3,3,0,3,3};
unsigned char OLL_49_alg[] = {R,U,R_,U_,RX,D_,R_,U,R,MZ,RY_};
std::vector<unsigned char> OLL_49_algo(OLL_49_alg, OLL_49_alg + sizeof(OLL_49_alg) / sizeof(unsigned char));

unsigned char OLL_50[CUBE_SIZE] = {4,0,4,4,4,4,4,0,4,2,2,2,2,2,2,0,4,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_50_alg[] = {L_,R,U,R_,U_,L,R_,F,R,F_};
std::vector<unsigned char> OLL_50_algo(OLL_50_alg, OLL_50_alg + sizeof(OLL_50_alg) / sizeof(unsigned char));

unsigned char OLL_51[CUBE_SIZE] = {4,0,4,4,4,0,4,4,4,2,2,2,2,2,2,0,4,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,0,3,3,4,3,3,0,3,3};
unsigned char OLL_51_alg[] = {MX,U_,MX_,U_,U_,MX,U_,MX_};
std::vector<unsigned char> OLL_51_algo(OLL_51_alg, OLL_51_alg + sizeof(OLL_51_alg) / sizeof(unsigned char));

unsigned char OLL_52[CUBE_SIZE] = {0,0,0,4,4,4,0,0,4,2,2,2,2,2,2,0,4,4,6,6,4,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,4,4,0,5,5,5,5,5,5,0,3,3,0,3,3,0,3,3};
unsigned char OLL_52_alg[] = {R_,F,R,U,R_,F_,R,RZ,L,U_,L_};
std::vector<unsigned char> OLL_52_algo(OLL_52_alg, OLL_52_alg + sizeof(OLL_52_alg) / sizeof(unsigned char));

unsigned char OLL_53[CUBE_SIZE] = {0,0,0,4,4,4,4,0,0,2,2,2,2,2,2,4,4,0,6,6,0,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,4,4,5,5,5,5,5,5,4,3,3,0,3,3,0,3,3};
unsigned char OLL_53_alg[] = {L,F_,L_,U_,L,F,L_,RZ_,R_,U,R};
std::vector<unsigned char> OLL_53_algo(OLL_53_alg, OLL_53_alg + sizeof(OLL_53_alg) / sizeof(unsigned char));

unsigned char OLL_54[CUBE_SIZE] = {0,0,0,4,4,4,4,0,0,2,2,2,2,2,2,0,4,4,6,6,4,6,6,0,6,6,0,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,0,3,3,0,3,3,4,3,3};
unsigned char OLL_54_alg[] = {R,B,R_,L,U,L_,U_,R,B_,R_};
std::vector<unsigned char> OLL_54_algo(OLL_54_alg, OLL_54_alg + sizeof(OLL_54_alg) / sizeof(unsigned char));

unsigned char OLL_55[CUBE_SIZE] = {0,0,0,4,4,4,0,0,4,2,2,2,2,2,2,4,4,0,6,6,0,6,6,0,6,6,4,1,1,1,1,1,1,1,1,1,0,4,0,5,5,5,5,5,5,4,3,3,0,3,3,0,3,3};
unsigned char OLL_55_alg[] = {L_,B_,L,R_,U_,R,U,L_,B,L};
std::vector<unsigned char> OLL_55_algo(OLL_55_alg, OLL_55_alg + sizeof(OLL_55_alg) / sizeof(unsigned char));

unsigned char OLL_56[CUBE_SIZE] = {0,4,4,0,4,4,0,0,0,2,2,2,2,2,2,0,0,0,6,6,4,6,6,4,6,6,0,1,1,1,1,1,1,1,1,1,4,4,0,5,5,5,5,5,5,0,3,3,0,3,3,4,3,3};
unsigned char OLL_56_alg[] = {r,U_,U_,R_,U_,R,U_,r_};
std::vector<unsigned char> OLL_56_algo(OLL_56_alg, OLL_56_alg + sizeof(OLL_56_alg) / sizeof(unsigned char));

unsigned char OLL_57[CUBE_SIZE] = {0,0,0,0,4,4,0,4,4,2,2,2,2,2,2,4,4,0,6,6,0,6,6,4,6,6,4,1,1,1,1,1,1,1,1,1,0,0,0,5,5,5,5,5,5,4,3,3,0,3,3,0,3,3};
unsigned char OLL_57_alg[] = {r_,U,U,R,U,R_,U,r};
std::vector<unsigned char> OLL_57_algo(OLL_57_alg, OLL_57_alg + sizeof(OLL_57_alg) / sizeof(unsigned char));



///////////////////////////////////
// PLL
////////////////////////////////////
unsigned char PLL_00[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6,6,6,6,1,1,1,1,1,1,1,1,1,5,5,5,5,5,5,5,5,5,3,3,3,3,3,3,3,3,3};
unsigned char PLL_00_alg[] = {};
std::vector<unsigned char> PLL_00_algo(PLL_00_alg, PLL_00_alg + sizeof(PLL_00_alg) / sizeof(unsigned char));

unsigned char PLL_01[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,3,2,6,6,6,6,6,2,6,6,6,1,1,1,1,1,1,1,1,1,5,5,5,5,5,5,5,5,5,3,3,3,6,3,3,3,3,3};
unsigned char PLL_01_alg[] = {B, B, U, L_, R, B, B, L, R_, U, B, B};
std::vector<unsigned char> PLL_01_algo(PLL_01_alg, PLL_01_alg + sizeof(PLL_01_alg) / sizeof(unsigned char));

unsigned char PLL_02[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,6,2,6,6,6,6,6,3,6,6,6,1,1,1,1,1,1,1,1,1,5,5,5,5,5,5,5,5,5,3,3,3,2,3,3,3,3,3};
unsigned char PLL_02_alg[] = {B, B, U_, L_, R, B, B, L, R_, U_, B, B};
std::vector<unsigned char> PLL_02_algo(PLL_02_alg, PLL_02_alg + sizeof(PLL_02_alg) / sizeof(unsigned char));

unsigned char PLL_03[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,3,2,3,6,6,2,6,6,6,6,6,6,1,1,1,1,1,1,1,1,1,5,5,2,5,5,5,5,5,5,5,3,3,3,3,3,6,3,3};
unsigned char PLL_03_alg[] = {RX, R_, U, R_, D, D, R, U_, R_, D, D, R, R};
std::vector<unsigned char> PLL_03_algo(PLL_03_alg, PLL_03_alg + sizeof(PLL_03_alg) / sizeof(unsigned char));

unsigned char PLL_04[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,6,2,6,6,6,5,6,6,6,6,6,3,1,1,1,1,1,1,1,1,1,2,5,5,5,5,5,5,5,5,2,3,3,3,3,3,3,3,3};
unsigned char PLL_04_alg[] = {RX, L, U_, L, D, D, L_, U, L, D, D, L, L};
std::vector<unsigned char> PLL_04_algo(PLL_04_alg, PLL_04_alg + sizeof(PLL_04_alg) / sizeof(unsigned char));

unsigned char PLL_05[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,6,2,6,6,6,6,6,2,6,6,6,1,1,1,1,1,1,1,1,1,5,3,5,5,5,5,5,5,5,3,3,3,5,3,3,3,3,3};
unsigned char PLL_05_alg[] = {RX_,R,U_,R_,U,D,R_,D,U_,R_,U,R,D,D,F};
std::vector<unsigned char> PLL_05_algo(PLL_05_alg, PLL_05_alg + sizeof(PLL_05_alg) / sizeof(unsigned char));

unsigned char PLL_06[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,6,5,2,6,6,5,6,6,6,6,6,2,1,1,1,1,1,1,1,1,1,6,2,5,5,5,5,5,5,5,3,3,3,3,3,3,3,3,3};
unsigned char PLL_06_alg[] = {RX_,R,R,U_,R,RX,D,D,r_,D,r,D,D,RX_,R,D,R,U,R_,D_};
std::vector<unsigned char> PLL_06_algo(PLL_06_alg, PLL_06_alg + sizeof(PLL_06_alg) / sizeof(unsigned char));

unsigned char PLL_07[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,3,6,6,6,6,6,3,6,6,6,1,1,1,1,1,1,1,1,1,5,5,3,5,5,5,5,5,5,5,3,3,6,3,3,2,3,3};
unsigned char PLL_07_alg[] = {R, U, R_, U_, R_, F, R, R, U_, R_, U_, R, U, R_, F_};
std::vector<unsigned char> PLL_07_algo(PLL_07_alg, PLL_07_alg + sizeof(PLL_07_alg) / sizeof(unsigned char));

unsigned char PLL_08[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,3,2,6,6,6,2,6,6,5,6,6,6,1,1,1,1,1,1,1,1,1,5,6,5,5,5,5,5,5,5,2,3,3,3,3,3,3,3,3};
unsigned char PLL_08_alg[] = {U_, L, L, F_, L_, U_, L_, U, L, F, L_, U, U, L, U, U, L_};
std::vector<unsigned char> PLL_08_algo(PLL_08_alg, PLL_08_alg + sizeof(PLL_08_alg) / sizeof(unsigned char));

unsigned char PLL_09[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,3,2,6,6,6,2,6,6,6,6,6,6,1,1,1,1,1,1,1,1,1,5,3,5,5,5,5,5,5,5,2,3,3,5,3,3,3,3,3};
unsigned char PLL_09_alg[] = {U, R, R, F, R, U, R, U_, R_, F_, R, U, U, R_, U, U, R};
std::vector<unsigned char> PLL_09_algo(PLL_09_alg, PLL_09_alg + sizeof(PLL_09_alg) / sizeof(unsigned char));

unsigned char PLL_10[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,3,6,6,6,6,6,6,6,6,6,1,1,1,1,1,1,1,1,1,5,3,3,5,5,5,5,5,5,5,3,3,5,3,3,2,3,3};
unsigned char PLL_10_alg[] = {L_, U, R, U_, L, U, U, R_, U, R, U, U, R_};
std::vector<unsigned char> PLL_10_algo(PLL_10_alg, PLL_10_alg + sizeof(PLL_10_alg) / sizeof(unsigned char));

unsigned char PLL_11[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,6,2,2,6,6,5,6,6,5,6,6,2,1,1,1,1,1,1,1,1,1,6,6,5,5,5,5,5,5,5,3,3,3,3,3,3,3,3,3};
unsigned char PLL_11_alg[] = {R, U_, L_, U, R_, U, U, L, U_, L_, U, U, L};
std::vector<unsigned char> PLL_11_algo(PLL_11_alg, PLL_11_alg + sizeof(PLL_11_alg) / sizeof(unsigned char));

unsigned char PLL_12[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,5,6,6,6,6,6,3,6,6,3,1,1,1,1,1,1,1,1,1,2,5,5,5,5,5,5,5,5,6,3,3,6,3,3,3,3,3};
unsigned char PLL_12_alg[] = {R,U_,L,d,d,L_,U,L,R_,U_,R,U,U,r_,F,l_,U_};
std::vector<unsigned char> PLL_12_algo(PLL_12_alg, PLL_12_alg + sizeof(PLL_12_alg) / sizeof(unsigned char));

unsigned char PLL_13[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,5,2,2,6,6,3,6,6,3,6,6,6,1,1,1,1,1,1,1,1,1,5,5,2,5,5,5,5,5,5,3,3,3,6,3,3,6,3,3};
unsigned char PLL_13_alg[] = {L_,U,R_,U,U,L,U_,L_,R,U,R_,U,U,L,U_,R,U};
std::vector<unsigned char> PLL_13_algo(PLL_13_alg, PLL_13_alg + sizeof(PLL_13_alg) / sizeof(unsigned char));

unsigned char PLL_14[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,5,6,6,6,6,6,6,6,6,3,1,1,1,1,1,1,1,1,1,2,3,5,5,5,5,5,5,5,6,3,3,5,3,3,3,3,3};
unsigned char PLL_14_alg[] = {L_, U, R, U_, L, U, L_, U, R_, U_, L, U, U, R, U, U, R_};
std::vector<unsigned char> PLL_14_algo(PLL_14_alg, PLL_14_alg + sizeof(PLL_14_alg) / sizeof(unsigned char));

unsigned char PLL_15[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,5,6,2,6,6,3,6,6,2,6,6,6,1,1,1,1,1,1,1,1,1,5,5,2,5,5,5,5,5,5,3,3,3,3,3,3,6,3,3};
unsigned char PLL_15_alg[] = {F,R,U_,R_,U_,R,U,R_,F_,R,U,R_,U_,R_,F,R,F_};
std::vector<unsigned char> PLL_15_algo(PLL_15_alg, PLL_15_alg + sizeof(PLL_15_alg) / sizeof(unsigned char));

unsigned char PLL_16[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,3,2,6,6,6,2,6,6,6,6,6,5,1,1,1,1,1,1,1,1,1,3,5,6,5,5,5,5,5,5,2,3,3,3,3,3,5,3,3};
unsigned char PLL_16_alg[] = {F,R_,F_,L,F,R,F_,L,L,RX_,U_,R,U,L,U_,R_,U};
std::vector<unsigned char> PLL_16_algo(PLL_16_alg, PLL_16_alg + sizeof(PLL_16_alg) / sizeof(unsigned char));

unsigned char PLL_17[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,5,2,6,6,6,6,6,3,6,6,6,1,1,1,1,1,1,1,1,1,5,2,5,5,5,5,5,5,5,3,3,3,6,3,3,3,3,3};
unsigned char PLL_17_alg[] = {MX,MX,U,MX_,MX_,U,U,MX,MX,U,MX_,MX_};
std::vector<unsigned char> PLL_17_algo(PLL_17_alg, PLL_17_alg + sizeof(PLL_17_alg) / sizeof(unsigned char));

unsigned char PLL_18[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,3,6,6,6,6,6,5,6,6,3,1,1,1,1,1,1,1,1,1,2,3,6,5,5,5,5,5,5,5,3,3,6,3,3,5,3,3};
unsigned char PLL_18_alg[] = {L, L, u, L_, U, L_, U_, L, u_, r, r, RZ_, R_, D, R};
std::vector<unsigned char> PLL_18_algo(PLL_18_alg, PLL_18_alg + sizeof(PLL_18_alg) / sizeof(unsigned char));

unsigned char PLL_19[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,6,2,2,6,6,5,6,6,3,6,6,5,1,1,1,1,1,1,1,1,1,3,6,2,5,5,5,5,5,5,3,3,3,5,3,3,6,3,3};
unsigned char PLL_19_alg[] = {R, R, u_, R, U_, R, U, R_, u, l, l, RZ_, RX, RX, R, U_, R_};
std::vector<unsigned char> PLL_19_algo(PLL_19_alg, PLL_19_alg + sizeof(PLL_19_alg) / sizeof(unsigned char));

unsigned char PLL_20[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,3,6,5,6,6,2,6,6,5,6,6,2,1,1,1,1,1,1,1,1,1,6,2,5,5,5,5,5,5,5,6,3,3,3,3,3,3,3,3};
unsigned char PLL_20_alg[] = {R, U, R_, RZ_, R, R, u_, R, U_, R_, U, R_, u, R, R};
std::vector<unsigned char> PLL_20_algo(PLL_20_alg, PLL_20_alg + sizeof(PLL_20_alg) / sizeof(unsigned char));

unsigned char PLL_21[CUBE_SIZE] = {4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,5,3,6,6,6,3,6,6,6,6,6,6,1,1,1,1,1,1,1,1,1,5,2,3,5,5,5,5,5,5,2,3,3,5,3,3,2,3,3};
unsigned char PLL_21_alg[] = {L_, U_, L, RZ_, R_, R_, u, R_, U, R, U_, R, u_, R, R};
std::vector<unsigned char> PLL_21_algo(PLL_21_alg, PLL_21_alg + sizeof(PLL_21_alg) / sizeof(unsigned char));


Resolution_Friedriech::Resolution_Friedriech(MainWindow * fenprincipale) : Resolution(fenprincipale)
{
    fill_map();
}


void Resolution_Friedriech::fill_map()
{
   // Croix 1
    map_algorithms_Croix1["Arete_01"] = new Algorithm(FirstCroix1_01, FirstCroix1_01_algo, ":/methods/Images/Methods/Fridrich/Arete_01.png");
    map_algorithms_Croix1["Arete_02"] = new Algorithm(FirstCroix1_02, FirstCroix1_02_algo, ":/methods/Images/Methods/Fridrich/Arete_02.png");

    // F2L
    map_algorithms_F2L["F2L_00"] = new Algorithm(F2L_00, F2L_00_algo, ":/methods/Images/Methods/Fridrich/F2L_00.png");
    map_algorithms_F2L["F2L_01"] = new Algorithm(F2L_01, F2L_01_algo, ":/methods/Images/Methods/Fridrich/F2L_01.png");
    map_algorithms_F2L["F2L_02"] = new Algorithm(F2L_02, F2L_02_algo, ":/methods/Images/Methods/Fridrich/F2L_02.png");
    map_algorithms_F2L["F2L_03"] = new Algorithm(F2L_03, F2L_03_algo, ":/methods/Images/Methods/Fridrich/F2L_03.png");
    map_algorithms_F2L["F2L_04"] = new Algorithm(F2L_04, F2L_04_algo, ":/methods/Images/Methods/Fridrich/F2L_04.png");
    map_algorithms_F2L["F2L_05"] = new Algorithm(F2L_05, F2L_05_algo, ":/methods/Images/Methods/Fridrich/F2L_05.png");
    map_algorithms_F2L["F2L_06"] = new Algorithm(F2L_06, F2L_06_algo, ":/methods/Images/Methods/Fridrich/F2L_06.png");
    map_algorithms_F2L["F2L_07"] = new Algorithm(F2L_07, F2L_07_algo, ":/methods/Images/Methods/Fridrich/F2L_07.png");
    map_algorithms_F2L["F2L_08"] = new Algorithm(F2L_08, F2L_08_algo, ":/methods/Images/Methods/Fridrich/F2L_08.png");
    map_algorithms_F2L["F2L_09"] = new Algorithm(F2L_09, F2L_09_algo, ":/methods/Images/Methods/Fridrich/F2L_09.png");
    map_algorithms_F2L["F2L_10"] = new Algorithm(F2L_10, F2L_10_algo, ":/methods/Images/Methods/Fridrich/F2L_10.png");
    map_algorithms_F2L["F2L_11"] = new Algorithm(F2L_11, F2L_11_algo, ":/methods/Images/Methods/Fridrich/F2L_11.png");
    map_algorithms_F2L["F2L_12"] = new Algorithm(F2L_12, F2L_12_algo, ":/methods/Images/Methods/Fridrich/F2L_12.png");
    map_algorithms_F2L["F2L_13"] = new Algorithm(F2L_13, F2L_13_algo, ":/methods/Images/Methods/Fridrich/F2L_13.png");
    map_algorithms_F2L["F2L_14"] = new Algorithm(F2L_14, F2L_14_algo, ":/methods/Images/Methods/Fridrich/F2L_14.png");
    map_algorithms_F2L["F2L_15"] = new Algorithm(F2L_15, F2L_15_algo, ":/methods/Images/Methods/Fridrich/F2L_15.png");
    map_algorithms_F2L["F2L_16"] = new Algorithm(F2L_16, F2L_16_algo, ":/methods/Images/Methods/Fridrich/F2L_16.png");
    map_algorithms_F2L["F2L_17"] = new Algorithm(F2L_17, F2L_17_algo, ":/methods/Images/Methods/Fridrich/F2L_17.png");
    map_algorithms_F2L["F2L_18"] = new Algorithm(F2L_18, F2L_18_algo, ":/methods/Images/Methods/Fridrich/F2L_18.png");
    map_algorithms_F2L["F2L_19"] = new Algorithm(F2L_19, F2L_19_algo, ":/methods/Images/Methods/Fridrich/F2L_19.png");
    map_algorithms_F2L["F2L_20"] = new Algorithm(F2L_20, F2L_20_algo, ":/methods/Images/Methods/Fridrich/F2L_20.png");
    map_algorithms_F2L["F2L_21"] = new Algorithm(F2L_21, F2L_21_algo, ":/methods/Images/Methods/Fridrich/F2L_21.png");
    map_algorithms_F2L["F2L_22"] = new Algorithm(F2L_22, F2L_22_algo, ":/methods/Images/Methods/Fridrich/F2L_22.png");
    map_algorithms_F2L["F2L_23"] = new Algorithm(F2L_23, F2L_23_algo, ":/methods/Images/Methods/Fridrich/F2L_23.png");
    map_algorithms_F2L["F2L_24"] = new Algorithm(F2L_24, F2L_24_algo, ":/methods/Images/Methods/Fridrich/F2L_24.png");
    map_algorithms_F2L["F2L_25"] = new Algorithm(F2L_25, F2L_25_algo, ":/methods/Images/Methods/Fridrich/F2L_25.png");
    map_algorithms_F2L["F2L_26"] = new Algorithm(F2L_26, F2L_26_algo, ":/methods/Images/Methods/Fridrich/F2L_26.png");
    map_algorithms_F2L["F2L_27"] = new Algorithm(F2L_27, F2L_27_algo, ":/methods/Images/Methods/Fridrich/F2L_27.png");
    map_algorithms_F2L["F2L_28"] = new Algorithm(F2L_28, F2L_28_algo, ":/methods/Images/Methods/Fridrich/F2L_28.png");
    map_algorithms_F2L["F2L_29"] = new Algorithm(F2L_29, F2L_29_algo, ":/methods/Images/Methods/Fridrich/F2L_29.png");
    map_algorithms_F2L["F2L_30"] = new Algorithm(F2L_30, F2L_30_algo, ":/methods/Images/Methods/Fridrich/F2L_30.png");
    map_algorithms_F2L["F2L_31"] = new Algorithm(F2L_31, F2L_31_algo, ":/methods/Images/Methods/Fridrich/F2L_31.png");
    map_algorithms_F2L["F2L_32"] = new Algorithm(F2L_32, F2L_32_algo, ":/methods/Images/Methods/Fridrich/F2L_32.png");
    map_algorithms_F2L["F2L_33"] = new Algorithm(F2L_33, F2L_33_algo, ":/methods/Images/Methods/Fridrich/F2L_33.png");
    map_algorithms_F2L["F2L_34"] = new Algorithm(F2L_34, F2L_34_algo, ":/methods/Images/Methods/Fridrich/F2L_34.png");
    map_algorithms_F2L["F2L_35"] = new Algorithm(F2L_35, F2L_35_algo, ":/methods/Images/Methods/Fridrich/F2L_35.png");
    map_algorithms_F2L["F2L_36"] = new Algorithm(F2L_36, F2L_36_algo, ":/methods/Images/Methods/Fridrich/F2L_36.png");
    map_algorithms_F2L["F2L_37"] = new Algorithm(F2L_37, F2L_37_algo, ":/methods/Images/Methods/Fridrich/F2L_37.png");
    map_algorithms_F2L["F2L_38"] = new Algorithm(F2L_38, F2L_38_algo, ":/methods/Images/Methods/Fridrich/F2L_38.png");
    map_algorithms_F2L["F2L_39"] = new Algorithm(F2L_39, F2L_39_algo, ":/methods/Images/Methods/Fridrich/F2L_39.png");
    map_algorithms_F2L["F2L_40"] = new Algorithm(F2L_40, F2L_40_algo, ":/methods/Images/Methods/Fridrich/F2L_40.png");
    map_algorithms_F2L["F2L_41"] = new Algorithm(F2L_41, F2L_41_algo, ":/methods/Images/Methods/Fridrich/F2L_41.png");

    // F2L Multislotting
    map_algorithms_F2L_Multislotting["F2L_Multislot_01"] = new Algorithm(F2L_Multislot_01, F2L_Multislot_01_algo, ":/methods/Images/Methods/Fridrich/F2L_MultiSlot_01.png");
    map_algorithms_F2L_Multislotting["F2L_Multislot_02"] = new Algorithm(F2L_Multislot_02, F2L_Multislot_02_algo, ":/methods/Images/Methods/Fridrich/F2L_MultiSlot_02.png");
    map_algorithms_F2L_Multislotting["F2L_Multislot_03"] = new Algorithm(F2L_Multislot_03, F2L_Multislot_03_algo, ":/methods/Images/Methods/Fridrich/F2L_MultiSlot_03.png");
    map_algorithms_F2L_Multislotting["F2L_Multislot_04"] = new Algorithm(F2L_Multislot_04, F2L_Multislot_04_algo, ":/methods/Images/Methods/Fridrich/F2L_MultiSlot_04.png");
    map_algorithms_F2L_Multislotting["F2L_Multislot_05"] = new Algorithm(F2L_Multislot_05, F2L_Multislot_05_algo, ":/methods/Images/Methods/Fridrich/F2L_MultiSlot_05.png");

    // OLL
    map_algorithms_OLL["OLL_00"] = new Algorithm(OLL_00, OLL_00_algo, ":/methods/Images/Methods/Fridrich/OLL_00.png");
    map_algorithms_OLL["OLL_01"] = new Algorithm(OLL_01, OLL_01_algo, ":/methods/Images/Methods/Fridrich/OLL_01.png");
    map_algorithms_OLL["OLL_02"] = new Algorithm(OLL_02, OLL_02_algo, ":/methods/Images/Methods/Fridrich/OLL_02.png");
    map_algorithms_OLL["OLL_03"] = new Algorithm(OLL_03, OLL_03_algo, ":/methods/Images/Methods/Fridrich/OLL_03.png");
    map_algorithms_OLL["OLL_04"] = new Algorithm(OLL_04, OLL_04_algo, ":/methods/Images/Methods/Fridrich/OLL_04.png");
    map_algorithms_OLL["OLL_05"] = new Algorithm(OLL_05, OLL_05_algo, ":/methods/Images/Methods/Fridrich/OLL_05.png");
    map_algorithms_OLL["OLL_06"] = new Algorithm(OLL_06, OLL_06_algo, ":/methods/Images/Methods/Fridrich/OLL_06.png");
    map_algorithms_OLL["OLL_07"] = new Algorithm(OLL_07, OLL_07_algo, ":/methods/Images/Methods/Fridrich/OLL_07.png");
    map_algorithms_OLL["OLL_08"] = new Algorithm(OLL_08, OLL_08_algo, ":/methods/Images/Methods/Fridrich/OLL_08.png");
    map_algorithms_OLL["OLL_09"] = new Algorithm(OLL_09, OLL_09_algo, ":/methods/Images/Methods/Fridrich/OLL_09.png");
    map_algorithms_OLL["OLL_10"] = new Algorithm(OLL_10, OLL_10_algo, ":/methods/Images/Methods/Fridrich/OLL_10.png");
    map_algorithms_OLL["OLL_11"] = new Algorithm(OLL_11, OLL_11_algo, ":/methods/Images/Methods/Fridrich/OLL_11.png");
    map_algorithms_OLL["OLL_12"] = new Algorithm(OLL_12, OLL_12_algo, ":/methods/Images/Methods/Fridrich/OLL_12.png");
    map_algorithms_OLL["OLL_13"] = new Algorithm(OLL_13, OLL_13_algo, ":/methods/Images/Methods/Fridrich/OLL_13.png");
    map_algorithms_OLL["OLL_14"] = new Algorithm(OLL_14, OLL_14_algo, ":/methods/Images/Methods/Fridrich/OLL_14.png");
    map_algorithms_OLL["OLL_15"] = new Algorithm(OLL_15, OLL_15_algo, ":/methods/Images/Methods/Fridrich/OLL_15.png");
    map_algorithms_OLL["OLL_16"] = new Algorithm(OLL_16, OLL_16_algo, ":/methods/Images/Methods/Fridrich/OLL_16.png");
    map_algorithms_OLL["OLL_17"] = new Algorithm(OLL_17, OLL_17_algo, ":/methods/Images/Methods/Fridrich/OLL_17.png");
    map_algorithms_OLL["OLL_18"] = new Algorithm(OLL_18, OLL_18_algo, ":/methods/Images/Methods/Fridrich/OLL_18.png");
    map_algorithms_OLL["OLL_19"] = new Algorithm(OLL_19, OLL_19_algo, ":/methods/Images/Methods/Fridrich/OLL_19.png");
    map_algorithms_OLL["OLL_20"] = new Algorithm(OLL_20, OLL_20_algo, ":/methods/Images/Methods/Fridrich/OLL_20.png");
    map_algorithms_OLL["OLL_21"] = new Algorithm(OLL_21, OLL_21_algo, ":/methods/Images/Methods/Fridrich/OLL_21.png");
    map_algorithms_OLL["OLL_22"] = new Algorithm(OLL_22, OLL_22_algo, ":/methods/Images/Methods/Fridrich/OLL_22.png");
    map_algorithms_OLL["OLL_23"] = new Algorithm(OLL_23, OLL_23_algo, ":/methods/Images/Methods/Fridrich/OLL_23.png");
    map_algorithms_OLL["OLL_24"] = new Algorithm(OLL_24, OLL_24_algo, ":/methods/Images/Methods/Fridrich/OLL_24.png");
    map_algorithms_OLL["OLL_25"] = new Algorithm(OLL_25, OLL_25_algo, ":/methods/Images/Methods/Fridrich/OLL_25.png");
    map_algorithms_OLL["OLL_26"] = new Algorithm(OLL_26, OLL_26_algo, ":/methods/Images/Methods/Fridrich/OLL_26.png");
    map_algorithms_OLL["OLL_27"] = new Algorithm(OLL_27, OLL_27_algo, ":/methods/Images/Methods/Fridrich/OLL_27.png");
    map_algorithms_OLL["OLL_28"] = new Algorithm(OLL_28, OLL_28_algo, ":/methods/Images/Methods/Fridrich/OLL_28.png");
    map_algorithms_OLL["OLL_29"] = new Algorithm(OLL_29, OLL_29_algo, ":/methods/Images/Methods/Fridrich/OLL_29.png");
    map_algorithms_OLL["OLL_30"] = new Algorithm(OLL_30, OLL_30_algo, ":/methods/Images/Methods/Fridrich/OLL_30.png");
    map_algorithms_OLL["OLL_31"] = new Algorithm(OLL_31, OLL_31_algo, ":/methods/Images/Methods/Fridrich/OLL_31.png");
    map_algorithms_OLL["OLL_32"] = new Algorithm(OLL_32, OLL_32_algo, ":/methods/Images/Methods/Fridrich/OLL_32.png");
    map_algorithms_OLL["OLL_33"] = new Algorithm(OLL_33, OLL_33_algo, ":/methods/Images/Methods/Fridrich/OLL_33.png");
    map_algorithms_OLL["OLL_34"] = new Algorithm(OLL_34, OLL_34_algo, ":/methods/Images/Methods/Fridrich/OLL_34.png");
    map_algorithms_OLL["OLL_35"] = new Algorithm(OLL_35, OLL_35_algo, ":/methods/Images/Methods/Fridrich/OLL_35.png");
    map_algorithms_OLL["OLL_36"] = new Algorithm(OLL_36, OLL_36_algo, ":/methods/Images/Methods/Fridrich/OLL_36.png");
    map_algorithms_OLL["OLL_37"] = new Algorithm(OLL_37, OLL_37_algo, ":/methods/Images/Methods/Fridrich/OLL_37.png");
    map_algorithms_OLL["OLL_38"] = new Algorithm(OLL_38, OLL_38_algo, ":/methods/Images/Methods/Fridrich/OLL_38.png");
    map_algorithms_OLL["OLL_39"] = new Algorithm(OLL_39, OLL_39_algo, ":/methods/Images/Methods/Fridrich/OLL_39.png");
    map_algorithms_OLL["OLL_40"] = new Algorithm(OLL_40, OLL_40_algo, ":/methods/Images/Methods/Fridrich/OLL_40.png");
    map_algorithms_OLL["OLL_41"] = new Algorithm(OLL_41, OLL_41_algo, ":/methods/Images/Methods/Fridrich/OLL_41.png");
    map_algorithms_OLL["OLL_42"] = new Algorithm(OLL_42, OLL_42_algo, ":/methods/Images/Methods/Fridrich/OLL_42.png");
    map_algorithms_OLL["OLL_43"] = new Algorithm(OLL_43, OLL_43_algo, ":/methods/Images/Methods/Fridrich/OLL_43.png");
    map_algorithms_OLL["OLL_44"] = new Algorithm(OLL_44, OLL_44_algo, ":/methods/Images/Methods/Fridrich/OLL_44.png");
    map_algorithms_OLL["OLL_45"] = new Algorithm(OLL_45, OLL_45_algo, ":/methods/Images/Methods/Fridrich/OLL_45.png");
    map_algorithms_OLL["OLL_46"] = new Algorithm(OLL_46, OLL_46_algo, ":/methods/Images/Methods/Fridrich/OLL_46.png");
    map_algorithms_OLL["OLL_47"] = new Algorithm(OLL_47, OLL_47_algo, ":/methods/Images/Methods/Fridrich/OLL_47.png");
    map_algorithms_OLL["OLL_48"] = new Algorithm(OLL_48, OLL_48_algo, ":/methods/Images/Methods/Fridrich/OLL_48.png");
    map_algorithms_OLL["OLL_49"] = new Algorithm(OLL_49, OLL_49_algo, ":/methods/Images/Methods/Fridrich/OLL_49.png");
    map_algorithms_OLL["OLL_50"] = new Algorithm(OLL_50, OLL_50_algo, ":/methods/Images/Methods/Fridrich/OLL_50.png");
    map_algorithms_OLL["OLL_51"] = new Algorithm(OLL_51, OLL_51_algo, ":/methods/Images/Methods/Fridrich/OLL_51.png");
    map_algorithms_OLL["OLL_52"] = new Algorithm(OLL_52, OLL_52_algo, ":/methods/Images/Methods/Fridrich/OLL_52.png");
    map_algorithms_OLL["OLL_53"] = new Algorithm(OLL_53, OLL_53_algo, ":/methods/Images/Methods/Fridrich/OLL_53.png");
    map_algorithms_OLL["OLL_54"] = new Algorithm(OLL_54, OLL_54_algo, ":/methods/Images/Methods/Fridrich/OLL_54.png");
    map_algorithms_OLL["OLL_55"] = new Algorithm(OLL_55, OLL_55_algo, ":/methods/Images/Methods/Fridrich/OLL_55.png");
    map_algorithms_OLL["OLL_56"] = new Algorithm(OLL_56, OLL_56_algo, ":/methods/Images/Methods/Fridrich/OLL_56.png");
    map_algorithms_OLL["OLL_57"] = new Algorithm(OLL_57, OLL_57_algo, ":/methods/Images/Methods/Fridrich/OLL_57.png");

    // PLL
    map_algorithms_PLL["PLL_00"] = new Algorithm(PLL_00, PLL_00_algo, ":/methods/Images/Methods/Fridrich/PLL_00.png");
    map_algorithms_PLL["PLL_01"] = new Algorithm(PLL_01, PLL_01_algo, ":/methods/Images/Methods/Fridrich/PLL_01.png");
    map_algorithms_PLL["PLL_02"] = new Algorithm(PLL_02, PLL_02_algo, ":/methods/Images/Methods/Fridrich/PLL_02.png");
    map_algorithms_PLL["PLL_03"] = new Algorithm(PLL_03, PLL_03_algo, ":/methods/Images/Methods/Fridrich/PLL_03.png");
    map_algorithms_PLL["PLL_04"] = new Algorithm(PLL_04, PLL_04_algo, ":/methods/Images/Methods/Fridrich/PLL_04.png");
    map_algorithms_PLL["PLL_05"] = new Algorithm(PLL_05, PLL_05_algo, ":/methods/Images/Methods/Fridrich/PLL_05.png");
    map_algorithms_PLL["PLL_06"] = new Algorithm(PLL_06, PLL_06_algo, ":/methods/Images/Methods/Fridrich/PLL_06.png");
    map_algorithms_PLL["PLL_07"] = new Algorithm(PLL_07, PLL_07_algo, ":/methods/Images/Methods/Fridrich/PLL_07.png");
    map_algorithms_PLL["PLL_08"] = new Algorithm(PLL_08, PLL_08_algo, ":/methods/Images/Methods/Fridrich/PLL_08.png");
    map_algorithms_PLL["PLL_09"] = new Algorithm(PLL_09, PLL_09_algo, ":/methods/Images/Methods/Fridrich/PLL_09.png");
    map_algorithms_PLL["PLL_10"] = new Algorithm(PLL_10, PLL_10_algo, ":/methods/Images/Methods/Fridrich/PLL_10.png");
    map_algorithms_PLL["PLL_11"] = new Algorithm(PLL_11, PLL_11_algo, ":/methods/Images/Methods/Fridrich/PLL_11.png");
    map_algorithms_PLL["PLL_12"] = new Algorithm(PLL_12, PLL_12_algo, ":/methods/Images/Methods/Fridrich/PLL_12.png");
    map_algorithms_PLL["PLL_13"] = new Algorithm(PLL_13, PLL_13_algo, ":/methods/Images/Methods/Fridrich/PLL_13.png");
    map_algorithms_PLL["PLL_14"] = new Algorithm(PLL_14, PLL_14_algo, ":/methods/Images/Methods/Fridrich/PLL_14.png");
    map_algorithms_PLL["PLL_15"] = new Algorithm(PLL_15, PLL_15_algo, ":/methods/Images/Methods/Fridrich/PLL_15.png");
    map_algorithms_PLL["PLL_16"] = new Algorithm(PLL_16, PLL_16_algo, ":/methods/Images/Methods/Fridrich/PLL_16.png");
    map_algorithms_PLL["PLL_17"] = new Algorithm(PLL_17, PLL_17_algo, ":/methods/Images/Methods/Fridrich/PLL_17.png");
    map_algorithms_PLL["PLL_18"] = new Algorithm(PLL_18, PLL_18_algo, ":/methods/Images/Methods/Fridrich/PLL_18.png");
    map_algorithms_PLL["PLL_19"] = new Algorithm(PLL_19, PLL_19_algo, ":/methods/Images/Methods/Fridrich/PLL_19.png");
    map_algorithms_PLL["PLL_20"] = new Algorithm(PLL_20, PLL_20_algo, ":/methods/Images/Methods/Fridrich/PLL_20.png");
    map_algorithms_PLL["PLL_21"] = new Algorithm(PLL_21, PLL_21_algo, ":/methods/Images/Methods/Fridrich/PLL_21.png");

    complete_map(map_algorithms_Croix1);
    complete_map(map_algorithms_F2L);
    complete_map(map_algorithms_F2L_Multislotting);
    complete_map(map_algorithms_OLL);
    complete_map(map_algorithms_PLL);

    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >("", std::map<QString, Algorithm* >()));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("1) Croix"), map_algorithms_Croix1));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("2) F2L"), map_algorithms_F2L));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("2.1) F2L Multislotting (advanced)"), map_algorithms_F2L_Multislotting));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("3) OLL"), map_algorithms_OLL));
    map_steps.insert(std::pair<QString, std::map<QString, Algorithm* > >(QObject::tr("4) PLL"), map_algorithms_PLL));
}

bool Resolution_Friedriech::solve(const unsigned char cube[CUBE_SIZE], QProgressBar * progressbar)
{
    if (!check_ColorsCube(cube))
        return false;

    // Initialisation variables
    _progressbar = progressbar;
    if (_progressbar != NULL)
    {
        _progressbar->setValue(0);
        _progression = 0;
    }

    _progressionMax = 9;
    solution._list_steps.clear();
    solution._title = QObject::tr("Méthode Fridrich");

	
    unsigned char new_cube[CUBE_SIZE] = {0}, new_cube2[CUBE_SIZE] = {0};
    Copie_Cube(cube, new_cube2);
    Update_Colors(new_cube2, new_cube);

     if (Resolution_Match(new_cube, Variables::Rubik_Cube_Resolu))
     {
          throw CubeAlreadySolved();
     }
	

    // Résolution croix première face
    if (!Solve_Croix(new_cube))
       return false;

    // F2L
    if (!Solve_F2L(new_cube))
       return false;

    // OLL
    if (!Solve_OLL(new_cube))
       return false;

    // PLL
   if (!Solve_PLL(new_cube))
       return false;

    return true;
}




bool Resolution_Friedriech::Solve_Croix(unsigned char init_cube[CUBE_SIZE])
{
    // Initialisation variables
    Step step(QObject::tr("(1) Croix"));
    unsigned char cube[CUBE_SIZE] = {0}, new_cube[CUBE_SIZE] = {0}, target_cube[CUBE_SIZE] = {0};
    int search_depth = 6;
    std::list<unsigned char> aAlgo;

    // Remplissage liste
    const unsigned char cube10[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,4,0,0,4,0,0,0,0,0,0,0,0,5,0,0,5,0,0,0,0,0,6,0,0,0,0};
    const unsigned char cube11[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0};
    const unsigned char cube12[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,0,0,0,0};
    const unsigned char cube13[CUBE_SIZE] = {0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,6,6,0,0,0};
    std::list<unsigned char *> liste_cubes;
    unsigned char _cube10[CUBE_SIZE] = {0}, _cube11[CUBE_SIZE] = {0}, _cube12[CUBE_SIZE] = {0}, _cube13[CUBE_SIZE] = {0};
    Copie_Cube(cube10, _cube10);		liste_cubes.push_back(_cube10);
    Copie_Cube(cube11, _cube11);		liste_cubes.push_back(_cube11);
    Copie_Cube(cube12, _cube12);		liste_cubes.push_back(_cube12);
    Copie_Cube(cube13, _cube13);		liste_cubes.push_back(_cube13);
    
    // Mouvements
    std::vector<unsigned char> Mouvements;
    Mouvements.push_back(U);    Mouvements.push_back(U_);
    Mouvements.push_back(L);    Mouvements.push_back(L_);
    Mouvements.push_back(F);    Mouvements.push_back(F_);
    Mouvements.push_back(D);    Mouvements.push_back(D_);
    Mouvements.push_back(R);    Mouvements.push_back(R_);
    Mouvements.push_back(B);    Mouvements.push_back(B_);

    Copie_Cube(init_cube, cube);
    Copie_Cube(cube_Step0_empty, target_cube);

    int i = 1;
    while (!liste_cubes.empty())
    {
       if (Resolution_Directe(cube, liste_cubes, target_cube, Mouvements, aAlgo, search_depth))
       {
           Sequence(cube, aAlgo, new_cube);

           Algorithm Algo(QString("Arête "+QString::number(i)), cube, new_cube, target_cube, aAlgo);
           step._list_algos.push_back(Algo);

           Copie_Cube(new_cube, cube);

           progressStep(_progression++);		// x 4
        }
        else
        {
            return false;
        }

        i++;
    }

    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);
	
    return areCubesMatching(init_cube, cube_Step1_Croix1, RZ, aAlgo);
}




bool Resolution_Friedriech::Solve_F2L(unsigned char init_cube[CUBE_SIZE])
{
    Step step(QObject::tr("(2) F2L"));
    unsigned char cube[CUBE_SIZE] = {0}, target_cube[CUBE_SIZE]= {0}, new_cube[CUBE_SIZE] = {0}, init_cube2[CUBE_SIZE] = {0};
    std::list<unsigned char> aAlgo, aNewAlgo;

    // Mouvements
    std::vector<unsigned char> Mouvements;
    Mouvements.push_back(RZ);
    Mouvements.push_back(U);

    Copie_Cube(init_cube, cube);
    Copie_Cube(cube_Step1_Croix1, target_cube);
    Copie_Cube(cube, init_cube2);
	
	bool multislotting_enabled = false;
    int c = 1;
    int gf = 0;
    while (!areCubesMatching(target_cube, cube_Step2_F2L, RZ, aAlgo) && gf<14)
    {
        QString aAlgoText;
        if (multislotting_enabled && Resolution_Algo(cube, map_algorithms_F2L_Multislotting, target_cube, new_cube, aAlgo, Mouvements, aAlgoText))
        {
            aNewAlgo.insert(aNewAlgo.end(), aAlgo.begin(), aAlgo.end());
            addAlgo(QString("Multislotting "+QString::number(c++)), aNewAlgo, init_cube2, target_cube, step);
            aAlgo.clear();
            aNewAlgo.clear();
            Copie_Cube(init_cube2, cube);
        }
        else if (Resolution_Algo(cube, map_algorithms_F2L, target_cube, new_cube, aAlgo, Mouvements, aAlgoText))
        {
            aNewAlgo.insert(aNewAlgo.end(), aAlgo.begin(), aAlgo.end());

            QString aText = "Slot "+QString::number(c++);
            if (Variables::_ALLOW_LEARNING_MODE_)
                aText += QString("   (")+aAlgoText+")";
            addAlgo(aText, aNewAlgo, init_cube2, target_cube, step);
            aAlgo.clear();
            aNewAlgo.clear();
            Copie_Cube(init_cube2, cube);
        }
        else
        {
            std::vector<unsigned char> aMouvementsAllowed;
            aMouvementsAllowed.push_back(RZ);

            unsigned char aNoMatchCube[CUBE_SIZE] = {0,0,0,0,4,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,6,6,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,5,5,0,5,5,0,0,0,0,3,3,0,3,3};

            unsigned char aUnblockingSequenceInt[] = {R, U, R_, RZ};
            std::list<unsigned char> aUnblockingSequence;
            aUnblockingSequence.assign(aUnblockingSequenceInt, aUnblockingSequenceInt+sizeof(aUnblockingSequenceInt)/sizeof(unsigned char));

            std::list<unsigned char> aUnblockingAlgo;
            bool res = unblockCube(cube, aNoMatchCube, aMouvementsAllowed, aUnblockingSequence, aUnblockingAlgo, new_cube);
            if (res)
            {
                Sequence(target_cube, aUnblockingAlgo, target_cube);
                aNewAlgo.insert(aNewAlgo.end(), aUnblockingAlgo.begin(), aUnblockingAlgo.end());
                Sequence(cube, aUnblockingAlgo, cube);

            }
            else
            {
                return false;
            }
        }

        progressStep(_progression++);		// x 4
        gf++;
    }

    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);
	
    return areCubesMatching(init_cube, cube_Step2_F2L, RZ, aAlgo);
}



bool Resolution_Friedriech::Solve_OLL(unsigned char init_cube[CUBE_SIZE])
{
    Step step(QObject::tr("(3) OLL"));
    unsigned char cube[CUBE_SIZE] = {0}, target_cube[CUBE_SIZE]= {0}, new_cube[CUBE_SIZE] = {0};
    std::list<unsigned char> aAlgo;
	
    // Mouvements
    std::vector<unsigned char> Mouvements;
    Mouvements.push_back(RZ);
    Mouvements.push_back(U);
	
    Copie_Cube(init_cube, cube);
    Update_Cube_Colors(cube, cube_Step2_F2L, target_cube);

    QString aAlgoText;
    if (!Resolution_Algo(cube, map_algorithms_OLL, target_cube, new_cube, aAlgo, Mouvements, aAlgoText))
    {
        return false;
    }

    QString aText = (Variables::_ALLOW_LEARNING_MODE_) ? aAlgoText : "OLL";
    addAlgo(aText, aAlgo, cube, target_cube, step);
    progressStep(_progression++);			// x 1

    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);
   
    return areCubesMatching(init_cube, cube_Step3_OLL, RZ, aAlgo);
}




bool Resolution_Friedriech::Solve_PLL(unsigned char init_cube[CUBE_SIZE])
{
    Step step(QObject::tr("(4) PLL"));
    unsigned char cube[CUBE_SIZE] = {0}, target_cube[CUBE_SIZE]= {0}, new_cube[CUBE_SIZE] = {0};
    std::list<unsigned char> aAlgo;
   
	// Mouvements
    std::vector<unsigned char> Mouvements;
    Mouvements.push_back(RZ);
    Mouvements.push_back(U);

    Copie_Cube(init_cube, cube);
    Update_Cube_Colors(cube, cube_Step3_OLL, target_cube);

    QString aAlgoText;
    if (!Resolution_Algo(cube, map_algorithms_PLL, target_cube, new_cube, aAlgo, Mouvements, aAlgoText))
    {
        return false;
    }

    QString aText = (Variables::_ALLOW_LEARNING_MODE_) ? aAlgoText : "PLL";
    addAlgo(aText, aAlgo, cube, target_cube, step);
    progressStep(_progression++);				// x 1

    Copie_Cube(cube, init_cube);
    solution._list_steps.push_back(step);

    return areCubesMatching(init_cube, cube_Step4_PLL, RZ, aAlgo);
}

