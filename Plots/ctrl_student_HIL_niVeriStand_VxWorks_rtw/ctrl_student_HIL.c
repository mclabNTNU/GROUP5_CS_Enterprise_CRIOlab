/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.161
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Feb 20 13:17:18 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

const real_T ctrl_student_HIL_RGND = 0.0;/* real_T ground */

/* Block signals (auto storage) */
B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states */
X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_student_HIL_T ctrl_student_HIL_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_T ctrl_student_HIL_M_;
RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M = &ctrl_student_HIL_M_;

/* Forward declaration for local functions */
static void ctrl_stude_twister_state_vector(uint32_T mt[625], real_T seed);
static real_T ctrl_student_eml_rand_mt19937ar(uint32_T state[625]);
static real_T ctrl_student_HIL_rand(DW_Freezesignal_ctrl_student__T *localDW);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S11>/Freeze signal' */
static void ctrl_stude_twister_state_vector(uint32_T mt[625], real_T seed)
{
  uint32_T r;
  int32_T mti;
  if (seed < 4.294967296E+9) {
    if (seed >= 0.0) {
      r = (uint32_T)seed;
    } else {
      r = 0U;
    }
  } else {
    r = MAX_uint32_T;
  }

  mt[0] = r;
  for (mti = 0; mti < 623; mti++) {
    r = ((r >> 30U ^ r) * 1812433253U + mti) + 1U;
    mt[mti + 1] = r;
  }

  mt[624] = 624U;
}

/* Function for MATLAB Function: '<S11>/Freeze signal' */
static real_T ctrl_student_eml_rand_mt19937ar(uint32_T state[625])
{
  real_T r;
  uint32_T u[2];
  uint32_T mti;
  uint32_T y;
  int32_T j;
  int32_T k;
  boolean_T b_isvalid;
  int32_T exitg1;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    u[0] = 0U;
    u[1] = 0U;
    for (j = 0; j < 2; j++) {
      mti = state[624] + 1U;
      if (mti >= 625U) {
        for (k = 0; k < 227; k++) {
          y = (state[1 + k] & 2147483647U) | (state[k] & 2147483648U);
          if ((int32_T)(y & 1U) == 0) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          state[k] = state[397 + k] ^ y;
        }

        for (k = 0; k < 396; k++) {
          y = (state[k + 227] & 2147483648U) | (state[228 + k] & 2147483647U);
          if ((int32_T)(y & 1U) == 0) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          state[k + 227] = state[k] ^ y;
        }

        y = (state[623] & 2147483648U) | (state[0] & 2147483647U);
        if ((int32_T)(y & 1U) == 0) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        state[623] = state[396] ^ y;
        mti = 1U;
      }

      y = state[(int32_T)mti - 1];
      state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      y ^= y >> 18U;
      u[j] = y;
    }

    r = ((real_T)(u[0] >> 5U) * 6.7108864E+7 + (real_T)(u[1] >> 6U)) *
      1.1102230246251565E-16;
    if (r == 0.0) {
      b_isvalid = ((state[624] >= 1U) && (state[624] < 625U));
      if (b_isvalid) {
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (state[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        ctrl_stude_twister_state_vector(state, 5489.0);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

/* Function for MATLAB Function: '<S11>/Freeze signal' */
static real_T ctrl_student_HIL_rand(DW_Freezesignal_ctrl_student__T *localDW)
{
  real_T r;
  int32_T hi;
  uint32_T test1;
  uint32_T test2;
  if (localDW->method == 4U) {
    hi = (int32_T)(localDW->state / 127773U);
    test1 = (localDW->state - hi * 127773U) * 16807U;
    test2 = 2836U * hi;
    if (test1 < test2) {
      test1 = (test1 - test2) + 2147483647U;
    } else {
      test1 -= test2;
    }

    localDW->state = test1;
    r = (real_T)test1 * 4.6566128752457969E-10;
  } else if (localDW->method == 5U) {
    test1 = 69069U * localDW->state_g[0] + 1234567U;
    test2 = localDW->state_g[1] << 13 ^ localDW->state_g[1];
    test2 ^= test2 >> 17;
    test2 ^= test2 << 5;
    localDW->state_g[0] = test1;
    localDW->state_g[1] = test2;
    r = (real_T)(test1 + test2) * 2.328306436538696E-10;
  } else {
    if (!localDW->state_not_empty) {
      memset(&localDW->state_m[0], 0, 625U * sizeof(uint32_T));
      ctrl_stude_twister_state_vector(localDW->state_m, 5489.0);
      localDW->state_not_empty = true;
    }

    r = ctrl_student_eml_rand_mt19937ar(localDW->state_m);
  }

  return r;
}

/*
 * Initial conditions for atomic system:
 *    '<S11>/Freeze signal'
 *    '<S12>/Freeze signal'
 *    '<S13>/Freeze signal'
 */
void ctrl_student__Freezesignal_Init(DW_Freezesignal_ctrl_student__T *localDW)
{
  localDW->eta_not_empty = false;
  localDW->state_not_empty = false;
  localDW->method = 7U;
  localDW->state = 1144108930U;
  localDW->state_g[0] = 362436069U;
  localDW->state_g[1] = 521288629U;
  localDW->t_1 = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S11>/Freeze signal'
 *    '<S12>/Freeze signal'
 *    '<S13>/Freeze signal'
 */
void ctrl_student_HIL_Freezesignal(real_T rtu_eta_in, real_T rtu_time, real_T
  rtu_random_value, real_T rtu_threshold, real_T rtu_length,
  B_Freezesignal_ctrl_student_H_T *localB, DW_Freezesignal_ctrl_student__T
  *localDW)
{
  /* MATLAB Function 'Noise and dropout generation/Dropout generation/Freeze Signal /Freeze signal': '<S14>:1' */
  if (!localDW->eta_not_empty) {
    /* '<S14>:1:3' */
    /* '<S14>:1:4' */
    localDW->eta = rtu_eta_in;
    localDW->eta_not_empty = true;
  }

  if (rtu_random_value > rtu_threshold) {
    /* '<S14>:1:8' */
    /* '<S14>:1:9' */
    localDW->t_1 = (0.5 * ctrl_student_HIL_rand(localDW) + 0.5) * rtu_length +
      rtu_time;
  }

  if (rtu_time >= localDW->t_1) {
    /* '<S14>:1:11' */
    /* '<S14>:1:12' */
    localDW->eta = rtu_eta_in;
  }

  /* '<S14>:1:15' */
  localB->eta_out = localDW->eta;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void ctrl_student_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_Gain_j;
  real_T rtb_NorthNoise;
  real_T rtb_TmpSignalConversionAtToFile[3];
  int32_T ixstart;
  real_T rtb_u[3];
  real_T u;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 +
        ctrl_student_HIL_M->Timing.clockTickH0 *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_M)) {
    ctrl_student_HIL_M->Timing.t[0] = rtsiGetT(&ctrl_student_HIL_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S10>/North Noise' */
    rtb_NorthNoise = ctrl_student_HIL_DW.NextOutput;

    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Par.SensNoiseEnabled'
     *  Gain: '<S10>/Ki4'
     *  RandomNumber: '<S10>/East Noise'
     *  RandomNumber: '<S10>/Heading Noise'
     */
    if (ctrl_student_HIL_P.Par.SensNoiseEnabled >
        ctrl_student_HIL_P.Switch_Threshold) {
      ctrl_student_HIL_B.Switch[0] = rtb_NorthNoise;
      ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_DW.NextOutput_j;
      ctrl_student_HIL_B.Switch[2] = ctrl_student_HIL_P.Ki4_Gain *
        ctrl_student_HIL_DW.NextOutput_g;
    } else {
      ctrl_student_HIL_B.Switch[0] = ctrl_student_HIL_P.Constant_Value[0];
      ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_P.Constant_Value[1];
      ctrl_student_HIL_B.Switch[2] = ctrl_student_HIL_P.Constant_Value[2];
    }

    /* End of Switch: '<S10>/Switch' */
  }

  /* Sum: '<S1>/Sum' */
  ctrl_student_HIL_B.Sum[0] = ctrl_student_HIL_B.Switch[0] +
    ctrl_student_HIL_B.x_in;
  ctrl_student_HIL_B.Sum[1] = ctrl_student_HIL_B.Switch[1] +
    ctrl_student_HIL_B.y_in;
  ctrl_student_HIL_B.Sum[2] = ctrl_student_HIL_B.Switch[2] +
    ctrl_student_HIL_B.psi_in;

  /* Clock: '<S11>/Clock' */
  ctrl_student_HIL_B.Clock = ctrl_student_HIL_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S11>/Random Number' */
    ctrl_student_HIL_B.RandomNumber = ctrl_student_HIL_DW.NextOutput_p;
  }

  /* MATLAB Function: '<S11>/Freeze signal' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   */
  ctrl_student_HIL_Freezesignal(ctrl_student_HIL_B.Sum[0],
    ctrl_student_HIL_B.Clock, ctrl_student_HIL_B.RandomNumber,
    ctrl_student_HIL_P.Par.Freeze.threshold,
    ctrl_student_HIL_P.Par.Freeze.length, &ctrl_student_HIL_B.sf_Freezesignal,
    &ctrl_student_HIL_DW.sf_Freezesignal);

  /* Clock: '<S12>/Clock' */
  ctrl_student_HIL_B.Clock_d = ctrl_student_HIL_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S12>/Random Number' */
    ctrl_student_HIL_B.RandomNumber_o = ctrl_student_HIL_DW.NextOutput_gm;
  }

  /* MATLAB Function: '<S12>/Freeze signal' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   */
  ctrl_student_HIL_Freezesignal(ctrl_student_HIL_B.Sum[1],
    ctrl_student_HIL_B.Clock_d, ctrl_student_HIL_B.RandomNumber_o,
    ctrl_student_HIL_P.Par.Freeze.threshold,
    ctrl_student_HIL_P.Par.Freeze.length, &ctrl_student_HIL_B.sf_Freezesignal_e,
    &ctrl_student_HIL_DW.sf_Freezesignal_e);

  /* Clock: '<S13>/Clock' */
  ctrl_student_HIL_B.Clock_n = ctrl_student_HIL_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S13>/Random Number' */
    ctrl_student_HIL_B.RandomNumber_g = ctrl_student_HIL_DW.NextOutput_f;
  }

  /* MATLAB Function: '<S13>/Freeze signal' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   */
  ctrl_student_HIL_Freezesignal(ctrl_student_HIL_B.Sum[2],
    ctrl_student_HIL_B.Clock_n, ctrl_student_HIL_B.RandomNumber_g,
    ctrl_student_HIL_P.Par.Freeze.threshold,
    ctrl_student_HIL_P.Par.Freeze.length, &ctrl_student_HIL_B.sf_Freezesignal_a,
    &ctrl_student_HIL_DW.sf_Freezesignal_a);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if (ctrl_student_HIL_P.Par.Freeze.Enable >
      ctrl_student_HIL_P.Switch_Threshold_f) {
    ctrl_student_HIL_B.Switch_j[0] = ctrl_student_HIL_B.sf_Freezesignal.eta_out;
    ctrl_student_HIL_B.Switch_j[1] =
      ctrl_student_HIL_B.sf_Freezesignal_e.eta_out;
    ctrl_student_HIL_B.Switch_j[2] =
      ctrl_student_HIL_B.sf_Freezesignal_a.eta_out;
  } else {
    ctrl_student_HIL_B.Switch_j[0] = ctrl_student_HIL_B.Sum[0];
    ctrl_student_HIL_B.Switch_j[1] = ctrl_student_HIL_B.Sum[1];
    ctrl_student_HIL_B.Switch_j[2] = ctrl_student_HIL_B.Sum[2];
  }

  /* End of Switch: '<S9>/Switch' */

  /* MATLAB Function: '<S2>/Detect droput' */
  /* MATLAB Function 'Signal Dropout detection/Detect droput': '<S17>:1' */
  if (!ctrl_student_HIL_DW.eta_old_not_empty) {
    /* '<S17>:1:3' */
    /* '<S17>:1:4' */
    ctrl_student_HIL_DW.eta_old[0] = ctrl_student_HIL_B.Switch_j[0];
    ctrl_student_HIL_DW.eta_old[1] = ctrl_student_HIL_B.Switch_j[1];
    ctrl_student_HIL_DW.eta_old[2] = ctrl_student_HIL_B.Switch_j[2];
    ctrl_student_HIL_DW.eta_old_not_empty = true;
  }

  /* '<S17>:1:6' */
  ctrl_student_HIL_B.dropout_log[0] = 0.0;
  ctrl_student_HIL_B.dropout_log[1] = 0.0;
  ctrl_student_HIL_B.dropout_log[2] = 0.0;

  /* '<S17>:1:7' */
  ctrl_student_HIL_B.dropout[0] = (ctrl_student_HIL_B.Switch_j[0] -
    ctrl_student_HIL_DW.eta_old[0] == 0.0);
  ctrl_student_HIL_B.dropout[1] = (ctrl_student_HIL_B.Switch_j[1] -
    ctrl_student_HIL_DW.eta_old[1] == 0.0);
  ctrl_student_HIL_B.dropout[2] = (ctrl_student_HIL_B.Switch_j[2] -
    ctrl_student_HIL_DW.eta_old[2] == 0.0);

  /* '<S17>:1:8' */
  if (ctrl_student_HIL_B.dropout[0]) {
    /* '<S17>:1:9' */
    /* '<S17>:1:10' */
    ctrl_student_HIL_B.dropout_log[0] = 1.0;
  }

  /* '<S17>:1:8' */
  if (ctrl_student_HIL_B.dropout[1]) {
    /* '<S17>:1:9' */
    /* '<S17>:1:10' */
    ctrl_student_HIL_B.dropout_log[1] = 1.0;
  }

  /* '<S17>:1:8' */
  if (ctrl_student_HIL_B.dropout[2]) {
    /* '<S17>:1:9' */
    /* '<S17>:1:10' */
    ctrl_student_HIL_B.dropout_log[2] = 1.0;
  }

  /* '<S17>:1:8' */
  /* '<S17>:1:13' */
  ctrl_student_HIL_DW.eta_old[0] = ctrl_student_HIL_B.Switch_j[0];
  ctrl_student_HIL_DW.eta_old[1] = ctrl_student_HIL_B.Switch_j[1];
  ctrl_student_HIL_DW.eta_old[2] = ctrl_student_HIL_B.Switch_j[2];

  /* End of MATLAB Function: '<S2>/Detect droput' */

  /* Integrator: '<S18>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = ((ZCEventType) (ctrl_student_HIL_B.dropout[2] &&
                (ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = (ZCSigState)
      ctrl_student_HIL_B.dropout[2];
    if (zcEvent || ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator_CSTATE = ctrl_student_HIL_B.r_in;
    }
  }

  rtb_Gain_j = ctrl_student_HIL_X.Integrator_CSTATE;

  /* Switch: '<S18>/Switch' */
  if (ctrl_student_HIL_B.dropout[2]) {
    ctrl_student_HIL_B.Switch_h = rtb_Gain_j;
  } else {
    ctrl_student_HIL_B.Switch_h = ctrl_student_HIL_B.r_in;
  }

  /* End of Switch: '<S18>/Switch' */

  /* MATLAB Function: '<S4>/k_psi' incorporates:
   *  Constant: '<S4>/Constant'
   *  Gain: '<S4>/Gain'
   *  Sum: '<S4>/Sum2'
   */
  /* MATLAB Function 'Surge Observer/k_psi': '<S23>:1' */
  /* '<S23>:1:3' */
  u = sin(ctrl_student_HIL_B.Switch_h) + cos(ctrl_student_HIL_B.Switch_h);
  if (u < 0.0) {
    u = -1.0;
  } else if (u > 0.0) {
    u = 1.0;
  } else {
    if (u == 0.0) {
      u = 0.0;
    }
  }

  ctrl_student_HIL_B.K_psi = (ctrl_student_HIL_P.Gain_Gain *
    ctrl_student_HIL_B.K_psi_in + ctrl_student_HIL_P.Par.K_psi_init) * u;

  /* End of MATLAB Function: '<S4>/k_psi' */
  /*  y = u; */

  /* Integrator: '<S19>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = ((ZCEventType) (ctrl_student_HIL_B.dropout[0] &&
                (ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_i != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_i = (ZCSigState)
      ctrl_student_HIL_B.dropout[0];
    if (zcEvent || ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator_CSTATE_l = ctrl_student_HIL_B.Switch_j[0];
    }
  }

  rtb_Gain_j = ctrl_student_HIL_X.Integrator_CSTATE_l;

  /* Switch: '<S19>/Switch' */
  if (ctrl_student_HIL_B.dropout[0]) {
    ctrl_student_HIL_B.Switch_o = rtb_Gain_j;
  } else {
    ctrl_student_HIL_B.Switch_o = ctrl_student_HIL_B.Switch_j[0];
  }

  /* End of Switch: '<S19>/Switch' */

  /* Integrator: '<S20>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = ((ZCEventType) (ctrl_student_HIL_B.dropout[1] &&
                (ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_n != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_n = (ZCSigState)
      ctrl_student_HIL_B.dropout[1];
    if (zcEvent || ctrl_student_HIL_DW.Integrator_IWORK_o.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator_CSTATE_m = ctrl_student_HIL_B.v_in;
    }
  }

  rtb_Gain_j = ctrl_student_HIL_X.Integrator_CSTATE_m;

  /* Switch: '<S20>/Switch' */
  if (ctrl_student_HIL_B.dropout[1]) {
    ctrl_student_HIL_B.Switch_l = rtb_Gain_j;
  } else {
    ctrl_student_HIL_B.Switch_l = ctrl_student_HIL_B.v_in;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Integrator: '<S4>/Integrator' */
  rtb_Gain_j = ctrl_student_HIL_X.Integrator_CSTATE_mg;

  /* Sum: '<S4>/Sum' incorporates:
   *  Product: '<S4>/Product'
   *  Sum: '<S4>/Sum1'
   */
  ctrl_student_HIL_B.Sum_c = (ctrl_student_HIL_B.Switch_o +
    ctrl_student_HIL_B.Switch_l) * ctrl_student_HIL_B.K_psi + rtb_Gain_j;

  /* Sum: '<Root>/Sum1' */
  ctrl_student_HIL_B.Sum1 = ctrl_student_HIL_B.u_in - ctrl_student_HIL_B.Sum_c;

  /* SignalConversion: '<Root>/TmpSignal ConversionAteta_after_droputInport1' */
  ctrl_student_HIL_B.TmpSignalConversionAteta_after_[0] =
    ctrl_student_HIL_B.Switch_o;
  ctrl_student_HIL_B.TmpSignalConversionAteta_after_[1] =
    ctrl_student_HIL_B.Switch_l;
  ctrl_student_HIL_B.TmpSignalConversionAteta_after_[2] =
    ctrl_student_HIL_B.Switch_h;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Gain: '<Root>/Gain' */
  rtb_Gain_j = ctrl_student_HIL_P.Gain_Gain_d * ctrl_student_HIL_B.PosYRight;

  /* Gain: '<Root>/Gain1' */
  ctrl_student_HIL_B.Gain1[0] = ctrl_student_HIL_P.Par.Thrust_lim[0] *
    rtb_Gain_j;
  ctrl_student_HIL_B.Gain1[1] = ctrl_student_HIL_P.Par.Thrust_lim[1] *
    ctrl_student_HIL_B.PosXRight;
  ctrl_student_HIL_B.Gain1[2] = ctrl_student_HIL_P.Par.Thrust_lim[2] *
    ctrl_student_HIL_B.PosXLeft;

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/Inverse of T'
   */
  /* MATLAB Function 'Thrust Allocation/MATLAB Function': '<S24>:1' */
  /* '<S24>:1:4' */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    rtb_u[ixstart] = ctrl_student_HIL_P.InverseofT_Value[ixstart + 6] *
      ctrl_student_HIL_B.Gain1[2] + (ctrl_student_HIL_P.InverseofT_Value[ixstart
      + 3] * ctrl_student_HIL_B.Gain1[1] +
      ctrl_student_HIL_P.InverseofT_Value[ixstart] * ctrl_student_HIL_B.Gain1[0]);
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* MATLAB Function: '<S3>/MATLAB Function1' */
  /* MATLAB Function 'Sixaxis2force/MATLAB Function1': '<S21>:1' */
  /* '<S21>:1:2' */
  u = sqrt(rtb_u[0] * rtb_u[0] + rtb_u[1] * rtb_u[1]);
  ixstart = 1;
  if (rtIsNaN(u)) {
    ixstart = 2;
    u = 1.0;
  }

  if ((ixstart < 2) && (1.0 < u)) {
    u = 1.0;
  }

  ctrl_student_HIL_B.u_VSP = u;

  /* '<S21>:1:3' */
  ctrl_student_HIL_B.alpha_VSP = rt_atan2d_snf(rtb_u[1], rtb_u[0]);

  /* '<S21>:1:4' */
  ctrl_student_HIL_B.u_BT = rtb_u[2];

  /* End of MATLAB Function: '<S3>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* ToFile: '<Root>/To File' */
    {
      if (!(++ctrl_student_HIL_DW.ToFile_IWORK.Decimation % 1) &&
          (ctrl_student_HIL_DW.ToFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          ctrl_student_HIL_DW.ToFile_IWORK.Decimation = 0;
          u[0] = ctrl_student_HIL_M->Timing.t[1];
          u[1] = ctrl_student_HIL_B.Sum_c;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(ctrl_student_HIL_M,
                              "Error writing to MAT-file u_hat.mat");
            return;
          }

          if (((++ctrl_student_HIL_DW.ToFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file u_hat.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++ctrl_student_HIL_DW.ToFile1_IWORK.Decimation % 1) &&
          (ctrl_student_HIL_DW.ToFile1_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          ctrl_student_HIL_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = ctrl_student_HIL_M->Timing.t[1];
          u[1] = ctrl_student_HIL_B.Sum1;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(ctrl_student_HIL_M,
                              "Error writing to MAT-file u_tilde.mat");
            return;
          }

          if (((++ctrl_student_HIL_DW.ToFile1_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file u_tilde.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File2' */
    {
      if (!(++ctrl_student_HIL_DW.ToFile2_IWORK.Decimation % 1) &&
          (ctrl_student_HIL_DW.ToFile2_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile2_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          ctrl_student_HIL_DW.ToFile2_IWORK.Decimation = 0;
          u[0] = ctrl_student_HIL_M->Timing.t[1];
          u[1] = ctrl_student_HIL_B.u_in;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(ctrl_student_HIL_M,
                              "Error writing to MAT-file u_real.mat");
            return;
          }

          if (((++ctrl_student_HIL_DW.ToFile2_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file u_real.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo File3Inport1' */
    rtb_TmpSignalConversionAtToFile[0] = ctrl_student_HIL_B.x_in;
    rtb_TmpSignalConversionAtToFile[1] = ctrl_student_HIL_B.y_in;
    rtb_TmpSignalConversionAtToFile[2] = ctrl_student_HIL_B.psi_in;

    /* ToFile: '<Root>/To File3' */
    {
      if (!(++ctrl_student_HIL_DW.ToFile3_IWORK.Decimation % 1) &&
          (ctrl_student_HIL_DW.ToFile3_IWORK.Count*4)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile3_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[4];
          ctrl_student_HIL_DW.ToFile3_IWORK.Decimation = 0;
          u[0] = ctrl_student_HIL_M->Timing.t[1];
          u[1] = rtb_TmpSignalConversionAtToFile[0];
          u[2] = rtb_TmpSignalConversionAtToFile[1];
          u[3] = rtb_TmpSignalConversionAtToFile[2];
          if (fwrite(u, sizeof(real_T), 4, fp) != 4) {
            rtmSetErrorStatus(ctrl_student_HIL_M,
                              "Error writing to MAT-file psi.mat");
            return;
          }

          if (((++ctrl_student_HIL_DW.ToFile3_IWORK.Count)*4)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file psi.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File4' */
    {
      if (!(++ctrl_student_HIL_DW.ToFile4_IWORK.Decimation % 1) &&
          (ctrl_student_HIL_DW.ToFile4_IWORK.Count*4)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile4_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[4];
          ctrl_student_HIL_DW.ToFile4_IWORK.Decimation = 0;
          u[0] = ctrl_student_HIL_M->Timing.t[1];
          u[1] = ctrl_student_HIL_B.Gain1[0];
          u[2] = ctrl_student_HIL_B.Gain1[1];
          u[3] = ctrl_student_HIL_B.Gain1[2];
          if (fwrite(u, sizeof(real_T), 4, fp) != 4) {
            rtmSetErrorStatus(ctrl_student_HIL_M,
                              "Error writing to MAT-file tau.mat");
            return;
          }

          if (((++ctrl_student_HIL_DW.ToFile4_IWORK.Count)*4)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file tau.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo File5Inport1' */
    rtb_TmpSignalConversionAtToFile[0] = ctrl_student_HIL_B.Switch_o;
    rtb_TmpSignalConversionAtToFile[1] = ctrl_student_HIL_B.Switch_l;
    rtb_TmpSignalConversionAtToFile[2] = ctrl_student_HIL_B.Switch_h;

    /* ToFile: '<Root>/To File5' */
    {
      if (!(++ctrl_student_HIL_DW.ToFile5_IWORK.Decimation % 1) &&
          (ctrl_student_HIL_DW.ToFile5_IWORK.Count*4)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile5_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[4];
          ctrl_student_HIL_DW.ToFile5_IWORK.Decimation = 0;
          u[0] = ctrl_student_HIL_M->Timing.t[1];
          u[1] = rtb_TmpSignalConversionAtToFile[0];
          u[2] = rtb_TmpSignalConversionAtToFile[1];
          u[3] = rtb_TmpSignalConversionAtToFile[2];
          if (fwrite(u, sizeof(real_T), 4, fp) != 4) {
            rtmSetErrorStatus(ctrl_student_HIL_M,
                              "Error writing to MAT-file eta_hat.mat");
            return;
          }

          if (((++ctrl_student_HIL_DW.ToFile5_IWORK.Count)*4)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file eta_hat.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<S2>/To File' */
    {
      if (!(++ctrl_student_HIL_DW.ToFile_IWORK_m.Decimation % 1) &&
          (ctrl_student_HIL_DW.ToFile_IWORK_m.Count*4)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile_PWORK_f.FilePtr;
        if (fp != (NULL)) {
          real_T u[4];
          ctrl_student_HIL_DW.ToFile_IWORK_m.Decimation = 0;
          u[0] = ctrl_student_HIL_M->Timing.t[1];
          u[1] = ctrl_student_HIL_B.dropout_log[0];
          u[2] = ctrl_student_HIL_B.dropout_log[1];
          u[3] = ctrl_student_HIL_B.dropout_log[2];
          if (fwrite(u, sizeof(real_T), 4, fp) != 4) {
            rtmSetErrorStatus(ctrl_student_HIL_M,
                              "Error writing to MAT-file dropout.mat");
            return;
          }

          if (((++ctrl_student_HIL_DW.ToFile_IWORK_m.Count)*4)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file dropout.mat.\n");
          }
        }
      }
    }
  }

  /* MATLAB Function: '<S4>/inside of integral' */
  /* MATLAB Function 'Surge Observer/inside of integral': '<S22>:1' */
  /* '<S22>:1:3' */
  /* '<S22>:1:7' */
  /* '<S22>:1:8' */
  ctrl_student_HIL_B.integral = (-((0.6555 - 0.3545 * fabs
    (ctrl_student_HIL_B.Sum_c)) - ctrl_student_HIL_B.Sum_c *
    ctrl_student_HIL_B.Sum_c * -3.787) * ctrl_student_HIL_B.Sum_c / 16.79 +
    ctrl_student_HIL_B.Gain1[0] / 16.79) - (cos(ctrl_student_HIL_B.Switch_h) +
    sin(ctrl_student_HIL_B.Switch_h)) * ctrl_student_HIL_B.K_psi *
    ctrl_student_HIL_B.Sum_c;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for RandomNumber: '<S10>/North Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * sqrt(ctrl_student_HIL_P.Par.Noise.Power)
      + ctrl_student_HIL_P.NorthNoise_Mean;

    /* Update for RandomNumber: '<S10>/East Noise' */
    ctrl_student_HIL_DW.NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_g) * sqrt
      (ctrl_student_HIL_P.Par.Noise.Power) + ctrl_student_HIL_P.EastNoise_Mean;

    /* Update for RandomNumber: '<S10>/Heading Noise' */
    ctrl_student_HIL_DW.NextOutput_g = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_i) * sqrt
      (ctrl_student_HIL_P.Par.Noise.Power) +
      ctrl_student_HIL_P.HeadingNoise_Mean;

    /* Update for RandomNumber: '<S11>/Random Number' */
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_gx) *
      ctrl_student_HIL_P.RandomNumber_StdDev +
      ctrl_student_HIL_P.RandomNumber_Mean;

    /* Update for RandomNumber: '<S12>/Random Number' */
    ctrl_student_HIL_DW.NextOutput_gm = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) *
      ctrl_student_HIL_P.RandomNumber_StdDev_b +
      ctrl_student_HIL_P.RandomNumber_Mean_g;

    /* Update for RandomNumber: '<S13>/Random Number' */
    ctrl_student_HIL_DW.NextOutput_f = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_n) *
      ctrl_student_HIL_P.RandomNumber_StdDev_h +
      ctrl_student_HIL_P.RandomNumber_Mean_a;
  }

  /* Update for Integrator: '<S18>/Integrator' */
  ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 0;

  /* Update for Integrator: '<S19>/Integrator' */
  ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading = 0;

  /* Update for Integrator: '<S20>/Integrator' */
  ctrl_student_HIL_DW.Integrator_IWORK_o.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_student_HIL_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_student_HIL_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_M->Timing.t[1] = ctrl_student_HIL_M->Timing.clockTick1 *
      ctrl_student_HIL_M->Timing.stepSize1 +
      ctrl_student_HIL_M->Timing.clockTickH1 *
      ctrl_student_HIL_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_derivatives(void)
{
  XDot_ctrl_student_HIL_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S18>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE = ctrl_student_HIL_B.Switch_j[2];
  }

  /* Derivatives for Integrator: '<S19>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_l = ctrl_student_HIL_B.u_in;
  }

  /* Derivatives for Integrator: '<S20>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_m = ctrl_student_HIL_B.Switch_j[1];
  }

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_mg = ctrl_student_HIL_B.integral;
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "u_hat.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_student_HIL_M, "Error creating .mat file u_hat.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error writing mat file header to file u_hat.mat");
      return;
    }

    ctrl_student_HIL_DW.ToFile_IWORK.Count = 0;
    ctrl_student_HIL_DW.ToFile_IWORK.Decimation = -1;
    ctrl_student_HIL_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "u_tilde.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error creating .mat file u_tilde.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error writing mat file header to file u_tilde.mat");
      return;
    }

    ctrl_student_HIL_DW.ToFile1_IWORK.Count = 0;
    ctrl_student_HIL_DW.ToFile1_IWORK.Decimation = -1;
    ctrl_student_HIL_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "u_real.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error creating .mat file u_real.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error writing mat file header to file u_real.mat");
      return;
    }

    ctrl_student_HIL_DW.ToFile2_IWORK.Count = 0;
    ctrl_student_HIL_DW.ToFile2_IWORK.Decimation = -1;
    ctrl_student_HIL_DW.ToFile2_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "psi.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_student_HIL_M, "Error creating .mat file psi.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,4,0,"ans")) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error writing mat file header to file psi.mat");
      return;
    }

    ctrl_student_HIL_DW.ToFile3_IWORK.Count = 0;
    ctrl_student_HIL_DW.ToFile3_IWORK.Decimation = -1;
    ctrl_student_HIL_DW.ToFile3_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File4' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "tau.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_student_HIL_M, "Error creating .mat file tau.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,4,0,"ans")) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error writing mat file header to file tau.mat");
      return;
    }

    ctrl_student_HIL_DW.ToFile4_IWORK.Count = 0;
    ctrl_student_HIL_DW.ToFile4_IWORK.Decimation = -1;
    ctrl_student_HIL_DW.ToFile4_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File5' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "eta_hat.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error creating .mat file eta_hat.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,4,0,"ans")) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error writing mat file header to file eta_hat.mat");
      return;
    }

    ctrl_student_HIL_DW.ToFile5_IWORK.Count = 0;
    ctrl_student_HIL_DW.ToFile5_IWORK.Decimation = -1;
    ctrl_student_HIL_DW.ToFile5_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<S2>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "dropout.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error creating .mat file dropout.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,4,0,"ans")) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error writing mat file header to file dropout.mat");
      return;
    }

    ctrl_student_HIL_DW.ToFile_IWORK_m.Count = 0;
    ctrl_student_HIL_DW.ToFile_IWORK_m.Decimation = -1;
    ctrl_student_HIL_DW.ToFile_PWORK_f.FilePtr = fp;
  }

  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for RandomNumber: '<S10>/North Noise' */
    tmp = floor(ctrl_student_HIL_P.NorthNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed = tseed;
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * sqrt(ctrl_student_HIL_P.Par.Noise.Power)
      + ctrl_student_HIL_P.NorthNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S10>/North Noise' */

    /* InitializeConditions for RandomNumber: '<S10>/East Noise' */
    tmp = floor(ctrl_student_HIL_P.EastNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_g = tseed;
    ctrl_student_HIL_DW.NextOutput_j = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_g) * sqrt
      (ctrl_student_HIL_P.Par.Noise.Power) + ctrl_student_HIL_P.EastNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S10>/East Noise' */

    /* InitializeConditions for RandomNumber: '<S10>/Heading Noise' */
    tmp = floor(ctrl_student_HIL_P.HeadingNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_i = tseed;
    ctrl_student_HIL_DW.NextOutput_g = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_i) * sqrt
      (ctrl_student_HIL_P.Par.Noise.Power) +
      ctrl_student_HIL_P.HeadingNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S10>/Heading Noise' */

    /* InitializeConditions for RandomNumber: '<S11>/Random Number' */
    tmp = floor(ctrl_student_HIL_P.RandomNumber_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_gx = tseed;
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_gx) *
      ctrl_student_HIL_P.RandomNumber_StdDev +
      ctrl_student_HIL_P.RandomNumber_Mean;

    /* End of InitializeConditions for RandomNumber: '<S11>/Random Number' */

    /* InitializeConditions for MATLAB Function: '<S11>/Freeze signal' */
    ctrl_student__Freezesignal_Init(&ctrl_student_HIL_DW.sf_Freezesignal);

    /* InitializeConditions for RandomNumber: '<S12>/Random Number' */
    tmp = floor(ctrl_student_HIL_P.RandomNumber_Seed_c);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_c = tseed;
    ctrl_student_HIL_DW.NextOutput_gm = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) *
      ctrl_student_HIL_P.RandomNumber_StdDev_b +
      ctrl_student_HIL_P.RandomNumber_Mean_g;

    /* End of InitializeConditions for RandomNumber: '<S12>/Random Number' */

    /* InitializeConditions for MATLAB Function: '<S12>/Freeze signal' */
    ctrl_student__Freezesignal_Init(&ctrl_student_HIL_DW.sf_Freezesignal_e);

    /* InitializeConditions for RandomNumber: '<S13>/Random Number' */
    tmp = floor(ctrl_student_HIL_P.RandomNumber_Seed_f);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_n = tseed;
    ctrl_student_HIL_DW.NextOutput_f = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_n) *
      ctrl_student_HIL_P.RandomNumber_StdDev_h +
      ctrl_student_HIL_P.RandomNumber_Mean_a;

    /* End of InitializeConditions for RandomNumber: '<S13>/Random Number' */

    /* InitializeConditions for MATLAB Function: '<S13>/Freeze signal' */
    ctrl_student__Freezesignal_Init(&ctrl_student_HIL_DW.sf_Freezesignal_a);

    /* InitializeConditions for MATLAB Function: '<S2>/Detect droput' */
    ctrl_student_HIL_DW.eta_old_not_empty = false;

    /* InitializeConditions for Integrator: '<S18>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator_CSTATE = 0.0;
    }

    ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S19>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator_CSTATE_l = 0.0;
    }

    ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S20>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator_CSTATE_m = 0.0;
    }

    ctrl_student_HIL_DW.Integrator_IWORK_o.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_mg = ctrl_student_HIL_P.Integrator_IC;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      rtmSetFirstInitCond(ctrl_student_HIL_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_student_HIL_terminate(void)
{
  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "u_hat.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error closing MAT-file u_hat.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error reopening MAT-file u_hat.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, ctrl_student_HIL_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error writing header for ans to MAT-file u_hat.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error closing MAT-file u_hat.mat");
        return;
      }

      ctrl_student_HIL_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "u_tilde.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error closing MAT-file u_tilde.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error reopening MAT-file u_tilde.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, ctrl_student_HIL_DW.ToFile1_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error writing header for ans to MAT-file u_tilde.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error closing MAT-file u_tilde.mat");
        return;
      }

      ctrl_student_HIL_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "u_real.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error closing MAT-file u_real.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error reopening MAT-file u_real.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, ctrl_student_HIL_DW.ToFile2_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error writing header for ans to MAT-file u_real.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error closing MAT-file u_real.mat");
        return;
      }

      ctrl_student_HIL_DW.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile3_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "psi.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error closing MAT-file psi.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error reopening MAT-file psi.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4, ctrl_student_HIL_DW.ToFile3_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error writing header for ans to MAT-file psi.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error closing MAT-file psi.mat");
        return;
      }

      ctrl_student_HIL_DW.ToFile3_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File4' */
  {
    FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile4_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "tau.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error closing MAT-file tau.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error reopening MAT-file tau.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4, ctrl_student_HIL_DW.ToFile4_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error writing header for ans to MAT-file tau.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error closing MAT-file tau.mat");
        return;
      }

      ctrl_student_HIL_DW.ToFile4_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File5' */
  {
    FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile5_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "eta_hat.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error closing MAT-file eta_hat.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error reopening MAT-file eta_hat.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4, ctrl_student_HIL_DW.ToFile5_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error writing header for ans to MAT-file eta_hat.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error closing MAT-file eta_hat.mat");
        return;
      }

      ctrl_student_HIL_DW.ToFile5_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S2>/To File' */
  {
    FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile_PWORK_f.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "dropout.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error closing MAT-file dropout.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error reopening MAT-file dropout.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4, ctrl_student_HIL_DW.ToFile_IWORK_m.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error writing header for ans to MAT-file dropout.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error closing MAT-file dropout.mat");
        return;
      }

      ctrl_student_HIL_DW.ToFile_PWORK_f.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_student_HIL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_student_HIL_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_T *ctrl_student_HIL(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_M->solverInfo,
                          &ctrl_student_HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_M->solverInfo, &rtmGetTPtr(ctrl_student_HIL_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_M->solverInfo,
                       &ctrl_student_HIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_M->solverInfo,
                 &ctrl_student_HIL_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_M->solverInfo,
      &ctrl_student_HIL_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_student_HIL_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_M->solverInfo, ctrl_student_HIL_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_M->ModelData.intgData.y = ctrl_student_HIL_M->ModelData.odeY;
  ctrl_student_HIL_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_M->ModelData.odeF[0];
  ctrl_student_HIL_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_M->ModelData.odeF[1];
  ctrl_student_HIL_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_M->ModelData.odeF[2];
  ctrl_student_HIL_M->ModelData.intgData.f[3] =
    ctrl_student_HIL_M->ModelData.odeF[3];
  ctrl_student_HIL_M->ModelData.contStates = ((real_T *) &ctrl_student_HIL_X);
  rtsiSetSolverData(&ctrl_student_HIL_M->solverInfo, (void *)
                    &ctrl_student_HIL_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_M->Timing.sampleTimes =
      (&ctrl_student_HIL_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_M->Timing.offsetTimes =
      (&ctrl_student_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_HIL_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_M, &ctrl_student_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_M, -1);
  ctrl_student_HIL_M->Timing.stepSize0 = 0.01;
  ctrl_student_HIL_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_student_HIL_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_M->solverInfoPtr = (&ctrl_student_HIL_M->solverInfo);
  ctrl_student_HIL_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_HIL_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_HIL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_M->ModelData.blockIO = ((void *) &ctrl_student_HIL_B);
  (void) memset(((void *) &ctrl_student_HIL_B), 0,
                sizeof(B_ctrl_student_HIL_T));

  /* parameters */
  ctrl_student_HIL_M->ModelData.defaultParam = ((real_T *)&ctrl_student_HIL_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_X;
    ctrl_student_HIL_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_X, 0,
                  sizeof(X_ctrl_student_HIL_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_M->ModelData.dwork = ((void *) &ctrl_student_HIL_DW);
  (void) memset((void *)&ctrl_student_HIL_DW, 0,
                sizeof(DW_ctrl_student_HIL_T));

  /* Initialize Sizes */
  ctrl_student_HIL_M->Sizes.numContStates = (4);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (112);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (45);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (285);/* Sum of parameter "widths" */
  return ctrl_student_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================*
 * This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#include "model_info.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;
double NIRT_GetValueByDataType(void* ptr,int subindex, int type, int Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 14:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,10,Complex);

   case 35:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 38:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 49:
    return NIRT_GetValueByDataType(ptr,subindex,21,Complex);

   case 50:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 51:
    return NIRT_GetValueByDataType(ptr,subindex,18,Complex);

   case 52:
    return NIRT_GetValueByDataType(ptr,subindex,15,Complex);

   case 53:
    return NIRT_GetValueByDataType(ptr,subindex,16,Complex);

   case 54:
    return NIRT_GetValueByDataType(ptr,subindex,17,Complex);

   case 55:
    return NIRT_GetValueByDataType(ptr,subindex,19,Complex);

   case 56:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);

   case 57:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 58:
    return NIRT_GetValueByDataType(ptr,subindex,21,Complex);

   case 59:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

long NIRT_SetValueByDataType(void* ptr,int subindex, double value, int type, int
  Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 14:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 27:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 28:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,10,Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 49:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,21,Complex);

   case 50:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 51:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,18,Complex);

   case 52:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,15,Complex);

   case 53:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,16,Complex);

   case 54:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,17,Complex);

   case 55:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,19,Complex);

   case 56:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);

   case 57:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 58:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,21,Complex);

   case 59:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_HIL_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Surge Observer/K_psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.K_psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowDown, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowUp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowLeft, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 19;
}

double ni_extout[28];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_c,0,0,0);
  } else {
    index += 1;
  }

  // u_out_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);
  } else {
    index += 1;
  }

  // u_tilde_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,0,0);
  } else {
    index += 1;
  }

  // eta_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,0,
      25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,1,
      25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,2,
      25,0);
  } else {
    index += 3;
  }

  // eta_after_droput: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_after_,0,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_after_,1,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAteta_after_,2,25,0);
  } else {
    index += 3;
  }

  // Sixaxis2force/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // Sixaxis2force/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // Sixaxis2force/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value_n,0,0,0);
  } else {
    index += 1;
  }

  // Sixaxis2force/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value_n,0,0,0);
  } else {
    index += 1;
  }

  // Sixaxis2force/u_BT: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);
  } else {
    index += 1;
  }

  // Sixaxis2force/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // Sixaxis2force/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,0,25,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,2,25,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,1,25,
      0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant1_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,
      0,25,0);
  } else {
    index += 1;
  }

  // tau_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,0,25,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,1,25,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,2,25,
      0);
  } else {
    index += 3;
  }

  // Surge Observer/K_psi_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.K_psi,0,0,0);
  } else {
    index += 1;
  }

  // Surge Observer/x_lowpass: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_o,0,
      0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 28;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum_c,0,0,0);

  // u_out_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);

  // u_tilde_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,0,0);

  // eta_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,0,25,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,1,25,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,2,25,
    0);

  // eta_after_droput: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_after_,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_after_,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAteta_after_,2,25,0);

  // Sixaxis2force/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,0,
    0);

  // Sixaxis2force/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_VSP,0,0,
    0);

  // Sixaxis2force/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value_n,0,0,0);

  // Sixaxis2force/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value_n,0,0,0);

  // Sixaxis2force/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);

  // Sixaxis2force/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);

  // Sixaxis2force/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,0,25,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,2,25,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,1,25,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,0,
    25,0);

  // tau_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,2,25,0);

  // Surge Observer/K_psi_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.K_psi,0,0,0);

  // Surge Observer/x_lowpass: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_o,0,0,
    0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil/Gain1/Gain", offsetof(P_ctrl_student_HIL_T, Par), 49, 1,
    2, 0, 0 },

  { 1, "ctrl_student_hil/Surge Observer/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 49, 1, 2, 2, 0 },

  { 2,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 4, 0 },

  { 3,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Par.SensNoiseEnabled/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 6, 0 },

  { 4,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/East Noise/Variance",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 8, 0 },

  { 5,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Heading Noise/Variance",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 10, 0 },

  { 6,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/North Noise/Variance",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 12, 0 },

  { 7,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal /Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal /Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 1/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 1/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 2/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 2/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 49, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value), 20, 3, 2, 26, 0 },

  { 14,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Ki4/Gain",
    offsetof(P_ctrl_student_HIL_T, Ki4_Gain), 50, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/North Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, NorthNoise_Mean), 50, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/North Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, NorthNoise_Seed), 50, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/East Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, EastNoise_Mean), 50, 1, 2, 34, 0 },

  { 18,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/East Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, EastNoise_Seed), 50, 1, 2, 36, 0 },

  { 19,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Heading Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, HeadingNoise_Mean), 50, 1, 2, 38, 0 },

  { 20,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Heading Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, HeadingNoise_Seed), 50, 1, 2, 40, 0 },

  { 21,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Switch/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch_Threshold), 50, 1, 2, 42, 0 },

  { 22,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal /Random Number/Mean",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Mean), 50, 1, 2, 44, 0 },

  { 23,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal /Random Number/StdDev",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_StdDev), 50, 1, 2, 46, 0 },

  { 24,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal /Random Number/Seed",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Seed), 50, 1, 2, 48, 0 },

  { 25,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 1/Random Number/Mean",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Mean_g), 50, 1, 2, 50, 0 },

  { 26,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 1/Random Number/StdDev",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_StdDev_b), 50, 1, 2, 52, 0 },

  { 27,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 1/Random Number/Seed",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Seed_c), 50, 1, 2, 54, 0 },

  { 28,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 2/Random Number/Mean",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Mean_a), 50, 1, 2, 56, 0 },

  { 29,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 2/Random Number/StdDev",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_StdDev_h), 50, 1, 2, 58, 0 },

  { 30,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 2/Random Number/Seed",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Seed_f), 50, 1, 2, 60, 0 },

  { 31,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Switch/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch_Threshold_f), 50, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil/Surge Observer/Gain/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain_Gain), 50, 1, 2, 64, 0 },

  { 33, "ctrl_student_hil/Surge Observer/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC), 50, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/Thrust Allocation/Inverse of T/Value", offsetof
    (P_ctrl_student_HIL_T, InverseofT_Value), 35, 9, 2, 68, 0 },

  { 35, "ctrl_student_hil/Gain/Gain", offsetof(P_ctrl_student_HIL_T, Gain_Gain_d),
    50, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/Sixaxis2force/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_n), 50, 1, 2, 72, 0 },

  { 37,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 50, 1, 2, 74, 0 },

  { 38,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_i), 50, 1, 2, 76, 0 },

  { 39,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 50, 1, 2, 78, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 40;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 3,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  3, 3,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Switch",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Switch)+0*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 1,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Switch",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Switch)+1*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 2, 0 },

  { 2,
    "ctrl_student_hil/Noise and dropout generation/Sensors Disturbances/Switch",
    0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Switch)+2*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/y_in", 0, "", offsetof(B_ctrl_student_HIL_T, y_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/x_in", 0, "", offsetof(B_ctrl_student_HIL_T, x_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/psi_in", 0, "", offsetof(B_ctrl_student_HIL_T, psi_in)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/Noise and dropout generation/Sum", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Sum)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/Noise and dropout generation/Sum", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Sum)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/Noise and dropout generation/Sum", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Sum)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal /Clock",
    0, "", offsetof(B_ctrl_student_HIL_T, Clock)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal /Random Number",
    0, "", offsetof(B_ctrl_student_HIL_T, RandomNumber)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 1/Clock",
    0, "", offsetof(B_ctrl_student_HIL_T, Clock_d)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 1/Random Number",
    0, "", offsetof(B_ctrl_student_HIL_T, RandomNumber_o)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 2/Clock",
    0, "", offsetof(B_ctrl_student_HIL_T, Clock_n)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 26, 0 },

  { 14,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 2/Random Number",
    0, "", offsetof(B_ctrl_student_HIL_T, RandomNumber_g)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Switch", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, Switch_j)+0*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Switch", 0,
    "(1,2)", offsetof(B_ctrl_student_HIL_T, Switch_j)+1*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Switch", 0,
    "(1,3)", offsetof(B_ctrl_student_HIL_T, Switch_j)+2*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/r_in", 0, "", offsetof(B_ctrl_student_HIL_T, r_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil/Signal Dropout detection/r/Switch", 0, "", offsetof
    (B_ctrl_student_HIL_T, Switch_h)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 38,
    0 },

  { 20, "ctrl_student_hil/Surge Observer/K_psi_in", 0, "", offsetof
    (B_ctrl_student_HIL_T, K_psi_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 40,
    0 },

  { 21, "ctrl_student_hil/Signal Dropout detection/x/Switch", 0, "", offsetof
    (B_ctrl_student_HIL_T, Switch_o)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 42,
    0 },

  { 22, "ctrl_student_hil/v_in", 0, "", offsetof(B_ctrl_student_HIL_T, v_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Signal Dropout detection/y/Switch", 0, "", offsetof
    (B_ctrl_student_HIL_T, Switch_l)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 46,
    0 },

  { 24, "ctrl_student_hil/Surge Observer/Sum", 0, "", offsetof
    (B_ctrl_student_HIL_T, Sum_c)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 48, 0
  },

  { 25, "ctrl_student_hil/u_in", 0, "", offsetof(B_ctrl_student_HIL_T, u_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/Sum1", 0, "", offsetof(B_ctrl_student_HIL_T, Sum1)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    54, 0 },

  { 28, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 56,
    0 },

  { 29, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 58,
    0 },

  { 30, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    60, 0 },

  { 31, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 62,
    0 },

  { 32, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 64,
    0 },

  { 33, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 70,
    0 },

  { 36, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 72,
    0 },

  { 37, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 74,
    0 },

  { 38, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    76, 0 },

  { 39, "ctrl_student_hil/Gain1", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T,
    Gain1)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2, 78, 0 },

  { 40, "ctrl_student_hil/Gain1", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T,
    Gain1)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2, 80, 0 },

  { 41, "ctrl_student_hil/Gain1", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T,
    Gain1)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2, 82, 0 },

  { 42, "ctrl_student_hil/Surge Observer/k_psi", 0, "K_psi", offsetof
    (B_ctrl_student_HIL_T, K_psi)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 84, 0
  },

  { 43, "ctrl_student_hil/Surge Observer/inside of integral", 0, "integral",
    offsetof(B_ctrl_student_HIL_T, integral)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 86, 0 },

  { 44, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 0, "u_VSP", offsetof
    (B_ctrl_student_HIL_T, u_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 88, 0
  },

  { 45, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 1, "alpha_VSP",
    offsetof(B_ctrl_student_HIL_T, alpha_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 90, 0 },

  { 46, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 2, "u_BT", offsetof
    (B_ctrl_student_HIL_T, u_BT)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 92, 0 },

  { 47, "ctrl_student_hil/Signal Dropout detection/Detect droput", 0,
    "dropout_log(1,1)", offsetof(B_ctrl_student_HIL_T, dropout_log)+0*sizeof
    (real_T), BLOCKIO_SIG, 25, 1, 2, 94, 0 },

  { 48, "ctrl_student_hil/Signal Dropout detection/Detect droput", 0,
    "dropout_log(1,2)", offsetof(B_ctrl_student_HIL_T, dropout_log)+1*sizeof
    (real_T), BLOCKIO_SIG, 25, 1, 2, 96, 0 },

  { 49, "ctrl_student_hil/Signal Dropout detection/Detect droput", 0,
    "dropout_log(1,3)", offsetof(B_ctrl_student_HIL_T, dropout_log)+2*sizeof
    (real_T), BLOCKIO_SIG, 25, 1, 2, 98, 0 },

  { 50, "ctrl_student_hil/Signal Dropout detection/Detect droput", 1,
    "dropout(1,1)", offsetof(B_ctrl_student_HIL_T, dropout)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 33, 1, 2, 100, 0 },

  { 51, "ctrl_student_hil/Signal Dropout detection/Detect droput", 1,
    "dropout(1,2)", offsetof(B_ctrl_student_HIL_T, dropout)+1*sizeof(boolean_T),
    BLOCKIO_SIG, 33, 1, 2, 102, 0 },

  { 52, "ctrl_student_hil/Signal Dropout detection/Detect droput", 1,
    "dropout(1,3)", offsetof(B_ctrl_student_HIL_T, dropout)+2*sizeof(boolean_T),
    BLOCKIO_SIG, 33, 1, 2, 104, 0 },

  { 53,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 2/Freeze signal",
    0, "eta_out", offsetof(B_ctrl_student_HIL_T, sf_Freezesignal_a.eta_out)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 106, 0 },

  { 54,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal 1/Freeze signal",
    0, "eta_out", offsetof(B_ctrl_student_HIL_T, sf_Freezesignal_e.eta_out)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 108, 0 },

  { 55,
    "ctrl_student_hil/Noise and dropout generation/Dropout generation/Freeze Signal /Freeze signal",
    0, "eta_out", offsetof(B_ctrl_student_HIL_T, sf_Freezesignal.eta_out)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 110, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 56;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 41;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 1, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "r_in", 0, EXT_IN, 1, 1, 1 },

  { 4, "Surge Observer/K_psi_in", 0, EXT_IN, 1, 1, 1 },

  { 5, "v_in", 0, EXT_IN, 1, 1, 1 },

  { 6, "u_in", 0, EXT_IN, 1, 1, 1 },

  { 7, "joystick/L2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 8, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 9, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 10, "joystick/R2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 11, "joystick/PosXLeft", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 13, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 14, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 15, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 16, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 17, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 18, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 0, "u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 1, "u_out_out", 0, EXT_OUT, 1, 1, 1 },

  { 2, "u_tilde_out", 0, EXT_OUT, 1, 1, 1 },

  { 3, "eta_m", 0, EXT_OUT, 3, 3, 1 },

  { 4, "eta_after_droput", 0, EXT_OUT, 3, 3, 1 },

  { 5, "Sixaxis2force/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 6, "Sixaxis2force/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Sixaxis2force/omega_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 8, "Sixaxis2force/omega_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 9, "Sixaxis2force/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Sixaxis2force/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Sixaxis2force/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 12, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 13, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 14, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 15, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 16, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 17, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 18, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 1,
    EXT_OUT, 1, 1, 1 },

  { 19, "tau_out", 0, EXT_OUT, 3, 3, 1 },

  { 20, "Surge Observer/K_psi_out", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Surge Observer/x_lowpass", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_student_hil";
static char* NI_CompiledModelVersion = "1.161";
static char* NI_CompiledModelDateTime = "Mon Feb 20 13:17:18 2017";
static char* NI_builder DataSection(".NIVS.builder") =
  "NI VeriStand 2014.0.0.82 (2014) RTW Build";
static char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2014.0.0.82";

/* Model Information Query fucntions for MATLAB
 */
/* dll information
 * Returns 1 for RTW DLL
 *		   2 for AutoCode DLL
 */
DLL_EXPORT long NIRT_GetBuildInfo(char* detail, long* len)
{
  // There are no console properties to set for VxWorks, because the console is simply serial output data.
  // Just do printf for VxWorks and ignore all console properties.
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  printf("\n*******************************************************************************\n");
  printf("%s\nModel Name: %s\nModel Version: %s\nCompiled On: %s",
         NI_builder, NI_CompiledModelName, NI_CompiledModelVersion,
         NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len>=(long)strlen(NI_builder))
    *len = strlen(NI_builder)+1;
  strncpy(detail,NI_builder,*len);
  return 1;
}

/*
 * Distinction between Index and ID:
 * Index is a long datatype (used to set parameter/probe signals).
 * ID on the other hand is a string (tag "2-3-2-12" for MatrixX/ Full path "f14/Gain/Gain" for Matlab).
 * If Bus support is added then signal path from the block name is added to the end of the port number (Model/subsystem1:1/X/A)
 * where X/A is the path from the block
 * NOTE: ID may not be the same as Paramname or signal name.
 */

/* signal information
   NOTE: signal ID == the blockname and port that feeds it extended with /sinalname.

   The port number in Simulation Environment is 1 indexed.. but on RT is 0 indexed.
 */
DLL_EXPORT long NIRT_GetSignalSpec(long* sidx, char* ID, long* ID_len, char
  * blkname, long *bnlen,
  long *portnum, char* signame, long *snlen, long *dattype, long* dims, long
  * numdim)
{
  long sigidx = *sidx;
  int i = 0;
  char *IDblk = 0;
  int IDport = 0;
  if (sigidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // parse ID into blkname and port
      i = strrchr(ID, ':') - ID;

      // malformed ID
      if (i<=0)
        return NI_SigListSize;

      //ID[i] = 0;
      IDblk = ID;
      IDport = atoi(ID+i+1);

      // lookup the table for matching ID
      // Bus support
      for (i=0;i<NI_SigListSize;i++) {
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname)+ 11, sizeof(char));

        //sprintf(tempID,"%s%s%s",NI_SigList[i].blockname,"/",NI_SigList[i].signalname);
        if (strlen(NI_SigList[i].signalname)>0)
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        else
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1))
          break;
        free(tempID);
      }

      if (i<NI_SigListSize)
        sigidx = *sidx = i;
      else
        return NI_SigListSize;
    } else                             // no index or ID specified.
      return NI_SigListSize;
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID) {
      // no need for return string to be null terminated!
      // 11 to accomodate ':','/', port number and null character
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0)
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      else
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      if ((long)strlen(tempID)<*ID_len)
        *ID_len = strlen(tempID);
      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].blockname)<*bnlen)
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].signalname)<*snlen)
        *snlen = strlen(NI_SigList[sigidx].signalname);
      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum)
      *portnum = NI_SigList[sigidx].portno;
    if (dattype)
      *dattype = NI_SigList[sigidx].datatype;
    if (dims && *numdim>=NI_SigList[sigidx].numofdims) {
      *numdim = NI_SigList[sigidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_SigListSize;
}

/*
 * Get parameter indices
 */
DLL_EXPORT long NIRT_GetParameterIndices(long* indices, long* len)
{
  long i;
  for (i=0;i<NI_ParamListSize && i<*len;i++)
    indices[i] = NI_ParamList[i].idx;
  *len = i;
  return NI_OK;
}

/*
 * parameter information
 *
 * if *pidx < 0, Lookup parameter by ID if ID != NULL.
 * if ID == NULL or no matching ID found, return number of parameters.
 *
 * plen  -> size of path
 * pnlen -> size of paramname
 * numdim -> size of dims array
 */
DLL_EXPORT long NIRT_GetParameterSpec(long* pidx, char* ID, long* ID_len, char
  * paramname, long *pnlen,
  long *dattype, long* dims, long* numdim)
{
  int i= 0;
  int paramidx = *pidx;
  if (paramidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // lookup the table for matching ID
      for (i=0;i<NI_ParamListSize;i++) {
        if (!strcmp(ID,NI_ParamList[i].paramname))
          break;
      }

      if (i<NI_ParamListSize)
        paramidx = *pidx = i;
      else
        return NI_ParamListSize;
    } else                             // no index or ID specified.
      return NI_ParamListSize;
  }

  if (paramidx>=0 && paramidx<NI_ParamListSize) {
    if (ID) {
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*ID_len)
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*pnlen)
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype)
      *dattype = NI_ParamList[paramidx].datatype;
    if (!numdim)
      return 0;
    if (*numdim>=NI_ParamList[paramidx].numofdims) {
      *numdim = NI_ParamList[paramidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_ParamListSize;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetParameterExpression(long paramidx, char* expression,
  long *exp_len)
{
  return 0;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetVariableName(long varidx, char* variable_name, long
  *var_len)
{
  return 0;
}

/*
 * NIRT_GetExtIOSpec
 *
 * Inputs:
 *		index: index of the task
 * Outputs:
 *		idx:  idx of the IO.
 *		name: Name of the IO block
 *		tid: task id
 *		type: EXT_IN or EXT_OUT
 *		dimX: size of 0th dimension
 *		dimY: size of 1th dimension
 * Return value: 0 if no error. (if index == -1, return number of tasks in the model)
 */
DLL_EXPORT long NIRT_GetExtIOSpec(long index, long *idx, char* name, long* tid,
  long *type, long *dims, long* numdims)
{
  if (index==-1)
    return NI_ExtListSize;
  if (idx)
    *idx = NI_ExtList[index].idx;
  if (name) {
    int sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid)
    *tid = NI_ExtList[index].TID;
  if (type)
    *type = NI_ExtList[index].type;
  if (numdims && dims) {
    if (*numdims>=2) {
      *numdims= 2;
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    } else
      *numdims= 0;
  }

  return 0;
}

/* Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG */
static long NI_ProbeOneSignal(long idx, double *value, long len, long *count,
  long vOffset, long vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (int)
    NI_SigList[idx].addr;
  long subindex = (vLength == -1) ? 0 : vOffset;
  long sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength + vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*
 * NIRT_ProbeSignals
 *
 * Inputs:
 *		sigindices: indeces of signals
 *		numsigs: number of signals
 *		len: total length of all signals
 * Outputs:
 *		value: probed signal data
 *		len: length of data (may vary from input)
 * Return value: equal to len
 */
DLL_EXPORT long NIRT_ProbeSignals(long* sigindices, long numsigs,
  double* value, long* len)
{
  int i, j, idx;
  long count = 0;
  if (!SITexportglobals.inCriticalSection)
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0)
      break;
    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        for (j = 0; j < 2; j++) {
          long vidx = NI_VirtualBlockSources[NI_SigList[idx].addr][j];
          long voff = NI_VirtualBlockOffsets[NI_SigList[idx].addr][j];
          long vlen = NI_VirtualBlockLengths[NI_SigList[idx].addr][j];
          if (vidx == -1)
            break;
          NI_ProbeOneSignal(vidx, value, *len, &count, voff, vlen);
        }
      } else
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
    }
  }

  *len = count;
  return count;
}

/* Copy the	statically initialized params into our copy of the param struct
   The undef allows us to access the real ctrl_student_HIL_P
   In the rest of the code ctrl_student_HIL_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_P, sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

static int NI_SetParamTxStatus = NI_OK;

// This function is called by the BGL to set parameters.  When a commit is requested (index < 0),
// the code enters a critical section shared with the TCL. This ensures that the flip occurs only
// when safe, and acts as a messaging scheme for us to copy back the parameters.
DLL_EXPORT long NIRT_SetParameter(long index, long subindex, double value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_student_HIL_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0)
        return NI_OK;
      SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                         1);
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    if (NI_SetParamTxStatus==NI_ERROR) {
      // fail the transaction.
      // copy old	list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1)
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_student_HIL_T));

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /*Do nothing if no new parameters were written after last commit*/
    if (WriteSideDirtyFlag == 0)
      return NI_OK;

    // commit changes
    S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
    WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
    READSIDE = 1 - READSIDE;
    SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
    ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

    // Copy back the newly set parameters to the writeside.
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_SetVectorParameter( unsigned long index, const double
  * paramvalues, unsigned long paramlength)
{
  unsigned int i = 0;
  long retval= NI_OK, temp_retval;
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    if (temp_retval = NIRT_SetValueByDataType(ptr, i, paramvalues[i],
         NI_ParamList[index].datatype, NI_ParamList[index].IsComplex))//assignment intended in if condition
      retval= temp_retval;
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

DLL_EXPORT long NIRT_SetScalarParameterInline( unsigned long index, unsigned
  long subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_GetParameter(long index, long subindex, double *value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

DLL_EXPORT long NIRT_GetVectorParameter(unsigned long index, double* paramvalues,
  unsigned long paramlength)
{
  char* ptr = NULL;
  unsigned int i = 0;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_GetSimState(long* numContStates, char* contStatesNames,
  double* contStates, long* numDiscStates, char* discStatesNames, double
  * discStates, long* numClockTicks, char* clockTicksNames, long* clockTicks)
{
  long count, idx;
  if (numContStates && numDiscStates && numClockTicks) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 4;
      *numDiscStates = 2762;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_l, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_m, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_m");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_mg, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_mg");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_j,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_g,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_gm,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_gm");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_f,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.K_psi_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.K_psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_out_out_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_out_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_tilde_out_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_tilde_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1,
      0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1,
      1, 25, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1,
      2, 25, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_after_droput_DWORK1, 0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_after_droput_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_after_droput_DWORK1, 1, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_after_droput_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_after_droput_DWORK1, 2, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_after_droput_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_out_DWORK1, 0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_out_DWORK1, 1, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_out_DWORK1, 2, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.K_psi_out_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.K_psi_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.x_lowpass_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.x_lowpass_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 0,
      25, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 1,
      25, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 2,
      25, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ToFile_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ToFile_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ToFile1_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ToFile1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ToFile2_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ToFile2_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ToFile3_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ToFile3_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ToFile4_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ToFile4_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ToFile5_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ToFile5_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile_PWORK_f, 0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile_PWORK_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_g, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_i, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_gx,
      0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_gx");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_n, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK_o.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator_IWORK_o.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile_IWORK.Count, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile_IWORK.Decimation, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile1_IWORK.Count, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile1_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile1_IWORK.Decimation, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile1_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile2_IWORK.Count, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile2_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile2_IWORK.Decimation, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile2_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile3_IWORK.Count, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile3_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile3_IWORK.Decimation, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile3_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile4_IWORK.Count, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile4_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile4_IWORK.Decimation, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile4_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile5_IWORK.Count, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile5_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile5_IWORK.Decimation, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile5_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile_IWORK_m.Count, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile_IWORK_m.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile_IWORK_m.Decimation, 0, 34, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile_IWORK_m.Decimation");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_in_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.K_psi_in_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.K_psi_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_hat_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_out_out_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_out_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_tilde_out_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_tilde_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_m_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_m_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_after_droput_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_after_droput_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_continuous_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXRight_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYRight_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.R2_continuous_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXLeft_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYLeft_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowDown_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowUp_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowRight_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_0_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_out_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.K_psi_out_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.K_psi_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_lowpass_DWORK2, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_lowpass_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_old_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_old_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.eta, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_a.eta");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.t_1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_a.t_1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.method, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_a.method");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.state, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_a.state");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.state_g, 0, 31, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_a.state_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.state_g, 1, 31, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_a.state_g");
    for (count = 0; count < 625; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.sf_Freezesignal_a.state_m, count, 32, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.sf_Freezesignal_a.state_m");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.eta_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_a.eta_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.state_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_a.state_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.eta, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_e.eta");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.t_1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_e.t_1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.method, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_e.method");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.state, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_e.state");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.state_g, 0, 31, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_e.state_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.state_g, 1, 31, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_e.state_g");
    for (count = 0; count < 625; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.sf_Freezesignal_e.state_m, count, 32, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.sf_Freezesignal_e.state_m");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.eta_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_e.eta_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.state_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_e.state_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.eta, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.eta");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.t_1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.t_1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.method, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.method");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.state, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.state");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.state_g, 0, 31, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.state_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.state_g, 1, 31, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.state_g");
    for (count = 0; count < 625; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.sf_Freezesignal.state_m, count, 32, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.sf_Freezesignal.state_m");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.eta_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.eta_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.state_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.state_not_empty");
  }

  if (clockTicks && clockTicksNames) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_SetSimState(double* contStates, double* discStates, long
  * clockTicks)
{
  long count, idx;
  if (contStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_l, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_m, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_mg, 0,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_j, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_g, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_gm, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_f, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_out_out_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_tilde_out_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1, 0, discStates[idx
      ++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1, 1, discStates[idx
      ++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1, 2, discStates[idx
      ++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_after_droput_DWORK1, 0,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_after_droput_DWORK1, 1,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_after_droput_DWORK1, 2,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 0,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 1,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 2,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_psi_out_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_lowpass_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 0, discStates[idx++],
      25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 1, discStates[idx++],
      25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 2, discStates[idx++],
      25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile1_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile2_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile3_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile4_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile5_PWORK, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_PWORK_f, 0,
      discStates[idx++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_g, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_i, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_gx, 0, discStates[idx
      ++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_n, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading,
      0, discStates[idx++], 10, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading, 0, discStates[idx
       ++], 10, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK_o.IcNeedsLoading, 0, discStates[idx
       ++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_IWORK.Count, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_IWORK.Decimation, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile1_IWORK.Count, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile1_IWORK.Decimation, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile2_IWORK.Count, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile2_IWORK.Decimation, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile3_IWORK.Count, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile3_IWORK.Decimation, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile4_IWORK.Count, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile4_IWORK.Decimation, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile5_IWORK.Count, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile5_IWORK.Decimation, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_IWORK_m.Count, 0,
      discStates[idx++], 34, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_IWORK_m.Decimation, 0,
      discStates[idx++], 34, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_psi_in_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_out_out_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_tilde_out_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_after_droput_DWORK2,
        count, discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_psi_out_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_lowpass_DWORK2, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 29, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 30, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old_not_empty, 0,
      discStates[idx++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_a.eta, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_a.t_1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_a.method, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_a.state, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_a.state_g, 0,
      discStates[idx++], 31, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_a.state_g, 1,
      discStates[idx++], 31, 0);
    for (count = 0; count < 625; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_a.state_m,
        count, discStates[idx++], 32, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_a.eta_not_empty,
      0, discStates[idx++], 8, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_a.state_not_empty, 0, discStates[idx
       ++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_e.eta, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_e.t_1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_e.method, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_e.state, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_e.state_g, 0,
      discStates[idx++], 31, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_e.state_g, 1,
      discStates[idx++], 31, 0);
    for (count = 0; count < 625; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_e.state_m,
        count, discStates[idx++], 32, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_e.eta_not_empty,
      0, discStates[idx++], 8, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_e.state_not_empty, 0, discStates[idx
       ++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.eta, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.t_1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.method, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state_g, 0,
      discStates[idx++], 31, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state_g, 1,
      discStates[idx++], 31, 0);
    for (count = 0; count < 625; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state_m,
        count, discStates[idx++], 32, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.eta_not_empty,
      0, discStates[idx++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state_not_empty,
      0, discStates[idx++], 8, 0);
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
