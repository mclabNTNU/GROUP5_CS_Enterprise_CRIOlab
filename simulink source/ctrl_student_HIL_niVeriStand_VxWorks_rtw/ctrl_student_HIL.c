/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.171
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Apr 24 12:18:43 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

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
  int_T nXc = 13;
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

/* Function for MATLAB Function: '<S25>/Freeze signal' */
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

/* Function for MATLAB Function: '<S25>/Freeze signal' */
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

/* Function for MATLAB Function: '<S25>/Freeze signal' */
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
    test1 = 69069U * localDW->state_j[0] + 1234567U;
    test2 = localDW->state_j[1] << 13 ^ localDW->state_j[1];
    test2 ^= test2 >> 17;
    test2 ^= test2 << 5;
    localDW->state_j[0] = test1;
    localDW->state_j[1] = test2;
    r = (real_T)(test1 + test2) * 2.328306436538696E-10;
  } else {
    if (!localDW->state_not_empty) {
      memset(&localDW->state_p[0], 0, 625U * sizeof(uint32_T));
      ctrl_stude_twister_state_vector(localDW->state_p, 5489.0);
      localDW->state_not_empty = true;
    }

    r = ctrl_student_eml_rand_mt19937ar(localDW->state_p);
  }

  return r;
}

/*
 * Initial conditions for atomic system:
 *    '<S25>/Freeze signal'
 *    '<S26>/Freeze signal'
 *    '<S27>/Freeze signal'
 */
void ctrl_student__Freezesignal_Init(DW_Freezesignal_ctrl_student__T *localDW)
{
  localDW->eta_not_empty = false;
  localDW->state_not_empty = false;
  localDW->method = 7U;
  localDW->state = 1144108930U;
  localDW->state_j[0] = 362436069U;
  localDW->state_j[1] = 521288629U;
  localDW->t_1 = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S25>/Freeze signal'
 *    '<S26>/Freeze signal'
 *    '<S27>/Freeze signal'
 */
void ctrl_student_HIL_Freezesignal(real_T rtu_eta_in, real_T rtu_time, real_T
  rtu_random_value, real_T rtu_threshold, real_T rtu_length,
  B_Freezesignal_ctrl_student_H_T *localB, DW_Freezesignal_ctrl_student__T
  *localDW)
{
  /* MATLAB Function 'Noise and dropout/Dropout generation/Freeze Signal /Freeze signal': '<S28>:1' */
  if (!localDW->eta_not_empty) {
    /* '<S28>:1:3' */
    /* '<S28>:1:4' */
    localDW->eta = rtu_eta_in;
    localDW->eta_not_empty = true;
  }

  if (rtu_random_value > rtu_threshold) {
    /* '<S28>:1:8' */
    /* '<S28>:1:9' */
    localDW->t_1 = (0.5 * ctrl_student_HIL_rand(localDW) + 0.5) * rtu_length +
      rtu_time;
  }

  if (rtu_time >= localDW->t_1) {
    /* '<S28>:1:11' */
    /* '<S28>:1:12' */
    localDW->eta = rtu_eta_in;
  }

  /* '<S28>:1:15' */
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
  real_T rtb_Integrator;
  real_T rtb_Integrator_i;
  real_T rtb_Integrator_ib;
  real_T rtb_TmpSignalConversionAtToFile[27];
  real_T *lastU;
  real_T psi_d;
  real_T N;
  real_T psi_d_s;
  real_T b_absxk;
  real_T b_t;
  real_T R[9];
  real_T tau_NED[3];
  int32_T ixstart;
  real_T rtb_z_1[3];
  real_T tmp[9];
  real_T tmp_0[9];
  real_T tmp_1[3];
  real_T tmp_2[9];
  real_T tmp_3[9];
  real_T tmp_4[9];
  real_T tmp_5[3];
  real_T tmp_6[9];
  real_T R_0[3];
  real_T tmp_7[3];
  real_T tmp_8[9];
  real_T tmp_9[9];
  int32_T i;
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
    /* MATLAB Function: '<S31>/MATLAB Function' incorporates:
     *  Constant: '<S24>/Step size'
     *  Constant: '<S3>/Constant'
     *  Memory: '<S31>/counter'
     */
    /* MATLAB Function 'Noise and dropout/Noise generator/Downsample	signal/MATLAB Function': '<S34>:1' */
    /* '<S34>:1:3' */
    if ((ctrl_student_HIL_DW.counter_PreviousInput + 1.0) *
        ctrl_student_HIL_P.Stepsize_Value >= 1.0 /
        ctrl_student_HIL_P.Par.Noise.Sample_freq) {
      /* '<S34>:1:4' */
      /* '<S34>:1:5' */
      ctrl_student_HIL_B.count = 0.0;
    } else {
      /* '<S34>:1:7' */
      ctrl_student_HIL_B.count = ctrl_student_HIL_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S31>/MATLAB Function' */

    /* Product: '<S37>/Product' incorporates:
     *  Constant: '<S24>/Step size'
     *  Constant: '<S3>/Constant1'
     *  Product: '<S37>/Divide'
     *  RandomNumber: '<S37>/White Noise'
     *  Sqrt: '<S37>/Sqrt'
     */
    ctrl_student_HIL_B.Product = sqrt(ctrl_student_HIL_P.Constant1_Value /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_DW.NextOutput;

    /* Product: '<S38>/Product' incorporates:
     *  Constant: '<S24>/Step size'
     *  Constant: '<S3>/Constant1'
     *  Product: '<S38>/Divide'
     *  RandomNumber: '<S38>/White Noise'
     *  Sqrt: '<S38>/Sqrt'
     */
    ctrl_student_HIL_B.Product_l = sqrt(ctrl_student_HIL_P.Constant1_Value /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_DW.NextOutput_m;

    /* Product: '<S36>/Product' incorporates:
     *  Constant: '<S24>/Step size'
     *  Constant: '<S3>/Constant1'
     *  Gain: '<S3>/Gain'
     *  Product: '<S36>/Divide'
     *  RandomNumber: '<S36>/White Noise'
     *  Sqrt: '<S36>/Sqrt'
     */
    ctrl_student_HIL_B.Product_c = sqrt(ctrl_student_HIL_P.Gain_Gain_i *
      ctrl_student_HIL_P.Constant1_Value / ctrl_student_HIL_P.Stepsize_Value) *
      ctrl_student_HIL_DW.NextOutput_n;
  }

  /* SignalConversion: '<Root>/TmpSignal ConversionAtetaInport1' */
  ctrl_student_HIL_B.eta[0] = ctrl_student_HIL_B.x_in;
  ctrl_student_HIL_B.eta[1] = ctrl_student_HIL_B.y_in;
  ctrl_student_HIL_B.eta[2] = ctrl_student_HIL_B.psi_in;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S32>/Hold' */
    ctrl_student_HIL_B.Hold[0] = ctrl_student_HIL_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_B.Hold[1] = ctrl_student_HIL_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_B.Hold[2] = ctrl_student_HIL_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S32>/MATLAB Function1' incorporates:
   *  Sum: '<S24>/Sum'
   */
  /* MATLAB Function 'Noise and dropout/Noise generator/Sample & hold/MATLAB Function1': '<S35>:1' */
  if (ctrl_student_HIL_B.count == 0.0) {
    /* '<S35>:1:4' */
    /* '<S35>:1:5' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Product +
      ctrl_student_HIL_B.eta[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Product_l +
      ctrl_student_HIL_B.eta[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Product_c +
      ctrl_student_HIL_B.eta[2];
  } else {
    /* '<S35>:1:7' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Hold[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Hold[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Hold[2];
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function1' */

  /* Switch: '<S24>/Switch' */
  if (ctrl_student_HIL_B.Enable_noise != 0.0) {
    ctrl_student_HIL_B.Switch[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_B.Switch[2] = ctrl_student_HIL_B.output[2];
  } else {
    ctrl_student_HIL_B.Switch[0] = ctrl_student_HIL_B.eta[0];
    ctrl_student_HIL_B.Switch[1] = ctrl_student_HIL_B.eta[1];
    ctrl_student_HIL_B.Switch[2] = ctrl_student_HIL_B.eta[2];
  }

  /* End of Switch: '<S24>/Switch' */

  /* Clock: '<S25>/Clock' */
  ctrl_student_HIL_B.Clock = ctrl_student_HIL_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S25>/Random Number' */
    ctrl_student_HIL_B.RandomNumber = ctrl_student_HIL_DW.NextOutput_o;
  }

  /* MATLAB Function: '<S25>/Freeze signal' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S25>/Constant1'
   */
  ctrl_student_HIL_Freezesignal(ctrl_student_HIL_B.Switch[0],
    ctrl_student_HIL_B.Clock, ctrl_student_HIL_B.RandomNumber,
    ctrl_student_HIL_P.Par.Freeze.threshold,
    ctrl_student_HIL_P.Par.Freeze.length, &ctrl_student_HIL_B.sf_Freezesignal,
    &ctrl_student_HIL_DW.sf_Freezesignal);

  /* Clock: '<S26>/Clock' */
  ctrl_student_HIL_B.Clock_f = ctrl_student_HIL_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S26>/Random Number' */
    ctrl_student_HIL_B.RandomNumber_c = ctrl_student_HIL_DW.NextOutput_os;
  }

  /* MATLAB Function: '<S26>/Freeze signal' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant1'
   */
  ctrl_student_HIL_Freezesignal(ctrl_student_HIL_B.Switch[1],
    ctrl_student_HIL_B.Clock_f, ctrl_student_HIL_B.RandomNumber_c,
    ctrl_student_HIL_P.Par.Freeze.threshold,
    ctrl_student_HIL_P.Par.Freeze.length, &ctrl_student_HIL_B.sf_Freezesignal_k,
    &ctrl_student_HIL_DW.sf_Freezesignal_k);

  /* Clock: '<S27>/Clock' */
  ctrl_student_HIL_B.Clock_b = ctrl_student_HIL_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S27>/Random Number' */
    ctrl_student_HIL_B.RandomNumber_l = ctrl_student_HIL_DW.NextOutput_e;
  }

  /* MATLAB Function: '<S27>/Freeze signal' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   */
  ctrl_student_HIL_Freezesignal(ctrl_student_HIL_B.Switch[2],
    ctrl_student_HIL_B.Clock_b, ctrl_student_HIL_B.RandomNumber_l,
    ctrl_student_HIL_P.Par.Freeze.threshold,
    ctrl_student_HIL_P.Par.Freeze.length, &ctrl_student_HIL_B.sf_Freezesignal_g,
    &ctrl_student_HIL_DW.sf_Freezesignal_g);

  /* Switch: '<S23>/Switch' */
  if (ctrl_student_HIL_B.Enable_dropout > ctrl_student_HIL_P.Switch_Threshold) {
    ctrl_student_HIL_B.Switch_m[0] = ctrl_student_HIL_B.sf_Freezesignal.eta_out;
    ctrl_student_HIL_B.Switch_m[1] =
      ctrl_student_HIL_B.sf_Freezesignal_k.eta_out;
    ctrl_student_HIL_B.Switch_m[2] =
      ctrl_student_HIL_B.sf_Freezesignal_g.eta_out;
  } else {
    ctrl_student_HIL_B.Switch_m[0] = ctrl_student_HIL_B.Switch[0];
    ctrl_student_HIL_B.Switch_m[1] = ctrl_student_HIL_B.Switch[1];
    ctrl_student_HIL_B.Switch_m[2] = ctrl_student_HIL_B.Switch[2];
  }

  /* End of Switch: '<S23>/Switch' */

  /* Integrator: '<S2>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_student_HIL_B.Model_reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      {
        int_T i1;
        real_T *xc = &ctrl_student_HIL_X.Integrator_CSTATE[0];
        for (i1=0; i1 < 9; i1++) {
          xc[i1] = (ctrl_student_HIL_P.Par.Observer.x_0[i1]);
        }
      }
    }
  }

  {
    int_T i1;
    real_T *y0 = &ctrl_student_HIL_B.Integrator[0];
    real_T *xc = &ctrl_student_HIL_X.Integrator_CSTATE[0];
    for (i1=0; i1 < 9; i1++) {
      y0[i1] = xc[i1];
    }
  }

  /* Integrator: '<S11>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_student_HIL_B.Model_reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator1_CSTATE =
        (ctrl_student_HIL_P.Par.Guidance.s_0);
    }
  }

  ctrl_student_HIL_B.Integrator1 = ctrl_student_HIL_X.Integrator1_CSTATE;

  /* MATLAB Function: '<S11>/eta_d_ellipsoid' */
  /* MATLAB Function 'Guidance and control/Guidance/eta_d_ellipsoid': '<S19>:1' */
  if (!ctrl_student_HIL_DW.psi_old_not_empty) {
    /* '<S19>:1:3' */
    /* '<S19>:1:4' */
    ctrl_student_HIL_DW.psi_old_not_empty = true;

    /* '<S19>:1:5' */
    ctrl_student_HIL_DW.psi_old = ctrl_student_HIL_B.ellipsoid_eta_0[2];
  }

  /* % eta_d */
  /* '<S19>:1:8' */
  /* '<S19>:1:9' */
  if (ctrl_student_HIL_B.ellipsoid_constant_heading_on_o != 0.0) {
    /* '<S19>:1:12' */
    psi_d = ctrl_student_HIL_B.ellipsoid_heading;
  } else {
    /* '<S19>:1:14' */
    psi_d = rt_atan2d_snf(ctrl_student_HIL_B.ellipsoid_r[1] * cos
                          (ctrl_student_HIL_B.Integrator1),
                          -ctrl_student_HIL_B.ellipsoid_r[0] * sin
                          (ctrl_student_HIL_B.Integrator1));

    /*      psi_d = atan(r(2)*cos(s)/(-r(1)*sin(s))); */
    if (psi_d < ctrl_student_HIL_DW.psi_old - 3.1415926535897931) {
      /* '<S19>:1:16' */
      /* '<S19>:1:17' */
      psi_d += 6.2831853071795862;
    }

    if (psi_d > ctrl_student_HIL_DW.psi_old + 3.1415926535897931) {
      /* '<S19>:1:19' */
      /* '<S19>:1:20' */
      psi_d += 6.2831853071795862;
    }

    /* '<S19>:1:22' */
    ctrl_student_HIL_DW.psi_old = psi_d;
  }

  /* '<S19>:1:24' */
  /* % eta_d_s */
  /* '<S19>:1:27' */
  /* '<S19>:1:28' */
  /* '<S19>:1:29' */
  N = 0.0;
  if (ctrl_student_HIL_B.ellipsoid_constant_heading_on_o != 0.0) {
    /* '<S19>:1:31' */
    psi_d_s = 0.0;
  } else {
    /* '<S19>:1:33' */
    N = ctrl_student_HIL_B.ellipsoid_r[0] * sin(ctrl_student_HIL_B.Integrator1);
    psi_d_s = ctrl_student_HIL_B.ellipsoid_r[1] * cos
      (ctrl_student_HIL_B.Integrator1);
    N = N * N + psi_d_s * psi_d_s;

    /* '<S19>:1:34' */
    psi_d_s = ctrl_student_HIL_B.ellipsoid_r[0] *
      ctrl_student_HIL_B.ellipsoid_r[1] / N;
  }

  /* '<S19>:1:36' */
  /* % eta_d_s_s */
  /* '<S19>:1:39' */
  /* '<S19>:1:40' */
  if (ctrl_student_HIL_B.ellipsoid_constant_heading_on_o != 0.0) {
    /* '<S19>:1:42' */
    N = 0.0;
  } else {
    /* '<S19>:1:44' */
    N = 2.0 * ctrl_student_HIL_B.ellipsoid_r[0] *
      ctrl_student_HIL_B.ellipsoid_r[1] * sin(ctrl_student_HIL_B.Integrator1) *
      cos(ctrl_student_HIL_B.Integrator1) * (ctrl_student_HIL_B.ellipsoid_r[1] *
      ctrl_student_HIL_B.ellipsoid_r[1] - ctrl_student_HIL_B.ellipsoid_r[0] *
      ctrl_student_HIL_B.ellipsoid_r[0]) / (N * N);
  }

  /* '<S19>:1:46' */

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  MATLAB Function: '<S11>/eta_d_ellipsoid'
   *  MATLAB Function: '<S11>/eta_d_straightline'
   */
  /* MATLAB Function 'Guidance and control/Guidance/eta_d_straightline': '<S20>:1' */
  /* % eta_d */
  /* '<S20>:1:3' */
  /* '<S20>:1:4' */
  /* eta_d = [x_d; y_d; psi_d]; */
  /* '<S20>:1:7' */
  /* % eta_d_s */
  /* '<S20>:1:10' */
  /* '<S20>:1:11' */
  /* '<S20>:1:12' */
  /* '<S20>:1:13' */
  /* % eta_d_s_s */
  /* '<S20>:1:16' */
  /* '<S20>:1:17' */
  /* '<S20>:1:18' */
  /* '<S20>:1:19' */
  if (ctrl_student_HIL_B.switch_straight_ellipsoid != 0.0) {
    ctrl_student_HIL_B.Switch_j[0] = ctrl_student_HIL_B.ellipsoid_r[0] * cos
      (ctrl_student_HIL_B.Integrator1) + ctrl_student_HIL_B.ellipsoid_c[0];
    ctrl_student_HIL_B.Switch_j[1] = ctrl_student_HIL_B.ellipsoid_r[1] * sin
      (ctrl_student_HIL_B.Integrator1) + ctrl_student_HIL_B.ellipsoid_c[1];
    ctrl_student_HIL_B.Switch_j[2] = psi_d;
    ctrl_student_HIL_B.Switch_j[3] = -ctrl_student_HIL_B.ellipsoid_r[0] * sin
      (ctrl_student_HIL_B.Integrator1);
    ctrl_student_HIL_B.Switch_j[4] = ctrl_student_HIL_B.ellipsoid_r[1] * cos
      (ctrl_student_HIL_B.Integrator1);
    ctrl_student_HIL_B.Switch_j[5] = psi_d_s;
    ctrl_student_HIL_B.Switch_j[6] = -ctrl_student_HIL_B.ellipsoid_r[0] * cos
      (ctrl_student_HIL_B.Integrator1);
    ctrl_student_HIL_B.Switch_j[7] = -ctrl_student_HIL_B.ellipsoid_r[1] * sin
      (ctrl_student_HIL_B.Integrator1);
    ctrl_student_HIL_B.Switch_j[8] = N;
  } else {
    ctrl_student_HIL_B.Switch_j[0] = (ctrl_student_HIL_P.Constant_Value[0] -
      ctrl_student_HIL_B.straight_eta_d_0[0]) * ctrl_student_HIL_B.Integrator1 +
      ctrl_student_HIL_B.straight_eta_d_0[0];
    ctrl_student_HIL_B.Switch_j[1] = (ctrl_student_HIL_P.Constant_Value[1] -
      ctrl_student_HIL_B.straight_eta_d_0[1]) * ctrl_student_HIL_B.Integrator1 +
      ctrl_student_HIL_B.straight_eta_d_0[1];
    ctrl_student_HIL_B.Switch_j[2] = 0.78539816339744828;
    ctrl_student_HIL_B.Switch_j[3] = ctrl_student_HIL_P.Constant_Value[0] -
      ctrl_student_HIL_B.straight_eta_d_0[0];
    ctrl_student_HIL_B.Switch_j[4] = ctrl_student_HIL_P.Constant_Value[1] -
      ctrl_student_HIL_B.straight_eta_d_0[1];
    ctrl_student_HIL_B.Switch_j[5] = 0.0;
    ctrl_student_HIL_B.Switch_j[6] = 0.0;
    ctrl_student_HIL_B.Switch_j[7] = 0.0;
    ctrl_student_HIL_B.Switch_j[8] = 0.0;
  }

  /* End of Switch: '<S11>/Switch' */

  /* MATLAB Function: '<S10>/z_1' */
  /* MATLAB Function 'Guidance and control/Control/z_1': '<S16>:1' */
  /* '<S16>:1:2' */
  /* '<S16>:1:3' */
  /* '<S16>:1:4' */
  tmp[0] = cos(ctrl_student_HIL_B.Integrator[2]);
  tmp[1] = -sin(ctrl_student_HIL_B.Integrator[2]);
  tmp[2] = 0.0;
  tmp[3] = sin(ctrl_student_HIL_B.Integrator[2]);
  tmp[4] = cos(ctrl_student_HIL_B.Integrator[2]);
  tmp[5] = 0.0;
  tmp[6] = 0.0;
  tmp[7] = 0.0;
  tmp[8] = 1.0;
  psi_d = ctrl_student_HIL_B.Integrator[0] - ctrl_student_HIL_B.Switch_j[0];
  N = ctrl_student_HIL_B.Integrator[1] - ctrl_student_HIL_B.Switch_j[1];
  psi_d_s = ctrl_student_HIL_B.Integrator[2] - ctrl_student_HIL_B.Switch_j[2];
  for (ixstart = 0; ixstart < 3; ixstart++) {
    rtb_z_1[ixstart] = tmp[ixstart + 6] * psi_d_s + (tmp[ixstart + 3] * N +
      tmp[ixstart] * psi_d);
  }

  /* End of MATLAB Function: '<S10>/z_1' */

  /* MATLAB Function: '<S11>/update law' */
  /* MATLAB Function 'Guidance and control/Guidance/update law': '<S21>:1' */
  /* '<S21>:1:2' */
  psi_d_s = 2.2250738585072014E-308;
  psi_d = fabs(ctrl_student_HIL_B.Switch_j[3]);
  if (psi_d > 2.2250738585072014E-308) {
    N = 1.0;
    psi_d_s = psi_d;
  } else {
    b_absxk = psi_d / 2.2250738585072014E-308;
    N = b_absxk * b_absxk;
  }

  psi_d = fabs(ctrl_student_HIL_B.Switch_j[4]);
  if (psi_d > psi_d_s) {
    b_absxk = psi_d_s / psi_d;
    N = N * b_absxk * b_absxk + 1.0;
    psi_d_s = psi_d;
  } else {
    b_absxk = psi_d / psi_d_s;
    N += b_absxk * b_absxk;
  }

  N = psi_d_s * sqrt(N);
  N = fabs(ctrl_student_HIL_B.u_ref) / N;

  /* '<S21>:1:3' */
  /* '<S21>:1:4' */
  psi_d = 2.2250738585072014E-308;
  b_absxk = fabs(ctrl_student_HIL_B.Switch_j[3]);
  if (b_absxk > 2.2250738585072014E-308) {
    psi_d_s = 1.0;
    psi_d = b_absxk;
  } else {
    b_t = b_absxk / 2.2250738585072014E-308;
    psi_d_s = b_t * b_t;
  }

  b_absxk = fabs(ctrl_student_HIL_B.Switch_j[4]);
  if (b_absxk > psi_d) {
    b_t = psi_d / b_absxk;
    psi_d_s = psi_d_s * b_t * b_t + 1.0;
    psi_d = b_absxk;
  } else {
    b_t = b_absxk / psi_d;
    psi_d_s += b_t * b_t;
  }

  b_absxk = fabs(ctrl_student_HIL_B.Switch_j[5]);
  if (b_absxk > psi_d) {
    b_t = psi_d / b_absxk;
    psi_d_s = psi_d_s * b_t * b_t + 1.0;
    psi_d = b_absxk;
  } else {
    b_t = b_absxk / psi_d;
    psi_d_s += b_t * b_t;
  }

  psi_d_s = psi_d * sqrt(psi_d_s);
  ctrl_student_HIL_B.s_dot = N - ((-(ctrl_student_HIL_B.Integrator[0] -
    ctrl_student_HIL_B.Switch_j[0]) * ctrl_student_HIL_B.Switch_j[3] +
    -(ctrl_student_HIL_B.Integrator[1] - ctrl_student_HIL_B.Switch_j[1]) *
    ctrl_student_HIL_B.Switch_j[4]) + -(ctrl_student_HIL_B.Integrator[2] -
    ctrl_student_HIL_B.Switch_j[2]) * ctrl_student_HIL_B.Switch_j[5]) *
    (ctrl_student_HIL_B.mu / psi_d_s);
  ctrl_student_HIL_B.U_s = N;

  /* End of MATLAB Function: '<S11>/update law' */

  /* MATLAB Function: '<S10>/alfa1' */
  /* MATLAB Function 'Guidance and control/Control/alfa1': '<S13>:1' */
  /* '<S13>:1:2' */
  /* '<S13>:1:3' */
  /* '<S13>:1:4' */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp[3 * ixstart] = -ctrl_student_HIL_B.K_p[3 * ixstart];
    tmp[1 + 3 * ixstart] = -ctrl_student_HIL_B.K_p[3 * ixstart + 1];
    tmp[2 + 3 * ixstart] = -ctrl_student_HIL_B.K_p[3 * ixstart + 2];
  }

  tmp_0[0] = cos(ctrl_student_HIL_B.Integrator[2]);
  tmp_0[1] = -sin(ctrl_student_HIL_B.Integrator[2]);
  tmp_0[2] = 0.0;
  tmp_0[3] = sin(ctrl_student_HIL_B.Integrator[2]);
  tmp_0[4] = cos(ctrl_student_HIL_B.Integrator[2]);
  tmp_0[5] = 0.0;
  tmp_0[6] = 0.0;
  tmp_0[7] = 0.0;
  tmp_0[8] = 1.0;
  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_1[ixstart] = tmp_0[ixstart + 6] * ctrl_student_HIL_B.Switch_j[5] +
      (tmp_0[ixstart + 3] * ctrl_student_HIL_B.Switch_j[4] + tmp_0[ixstart] *
       ctrl_student_HIL_B.Switch_j[3]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    ctrl_student_HIL_B.alfa1[ixstart] = ((tmp[ixstart + 3] * rtb_z_1[1] +
      tmp[ixstart] * rtb_z_1[0]) + tmp[ixstart + 6] * rtb_z_1[2]) +
      tmp_1[ixstart] * ctrl_student_HIL_B.U_s;
  }

  /* End of MATLAB Function: '<S10>/alfa1' */

  /* MATLAB Function 'Guidance and control/Control/D': '<S12>:1' */
  /* '<S12>:1:2' */
  /* '<S12>:1:3' */
  /* '<S12>:1:4' */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S12>:1:7' */
  /* '<S12>:1:11' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S12>:1:17' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Assembly of the damping matrix */
  /* '<S12>:1:24' */
  /* '<S12>:1:25' */
  /* '<S12>:1:26' */
  /*  using abs(r) */
  /* '<S12>:1:28' */
  /* '<S12>:1:29' */
  /* '<S12>:1:30' */
  /* '<S12>:1:32' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Derivative: '<S10>/Derivative' */
  /* MATLAB Function 'Guidance and control/Control/z_1_dot': '<S17>:1' */
  /* '<S17>:1:2' */
  /* '<S17>:1:3' */
  /* '<S17>:1:4' */
  /* '<S17>:1:5' */
  /* '<S17>:1:6' */
  if ((ctrl_student_HIL_DW.TimeStampA >= ctrl_student_HIL_M->Timing.t[0]) &&
      (ctrl_student_HIL_DW.TimeStampB >= ctrl_student_HIL_M->Timing.t[0])) {
    ctrl_student_HIL_B.Derivative = 0.0;
  } else {
    N = ctrl_student_HIL_DW.TimeStampA;
    lastU = &ctrl_student_HIL_DW.LastUAtTimeA;
    if (ctrl_student_HIL_DW.TimeStampA < ctrl_student_HIL_DW.TimeStampB) {
      if (ctrl_student_HIL_DW.TimeStampB < ctrl_student_HIL_M->Timing.t[0]) {
        N = ctrl_student_HIL_DW.TimeStampB;
        lastU = &ctrl_student_HIL_DW.LastUAtTimeB;
      }
    } else {
      if (ctrl_student_HIL_DW.TimeStampA >= ctrl_student_HIL_M->Timing.t[0]) {
        N = ctrl_student_HIL_DW.TimeStampB;
        lastU = &ctrl_student_HIL_DW.LastUAtTimeB;
      }
    }

    ctrl_student_HIL_B.Derivative = (ctrl_student_HIL_B.U_s - *lastU) /
      (ctrl_student_HIL_M->Timing.t[0] - N);
  }

  /* End of Derivative: '<S10>/Derivative' */

  /* MATLAB Function: '<S10>/alfa1_dot' */
  /* MATLAB Function 'Guidance and control/Control/alfa1_dot': '<S14>:1' */
  /* '<S14>:1:2' */
  /* '<S14>:1:3' */
  R[0] = cos(ctrl_student_HIL_B.Integrator[2]);
  R[3] = -sin(ctrl_student_HIL_B.Integrator[2]);
  R[6] = 0.0;
  R[1] = sin(ctrl_student_HIL_B.Integrator[2]);
  R[4] = cos(ctrl_student_HIL_B.Integrator[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* MATLAB Function: '<S10>/D' */
  /* '<S14>:1:4' */
  /* '<S14>:1:5' */
  /* '<S14>:1:6' */
  /* MATLAB Function 'Guidance and control/Control/z_2': '<S18>:1' */
  /* '<S18>:1:2' */
  /* MATLAB Function 'Guidance and control/Control/tau': '<S15>:1' */
  /* '<S15>:1:2' */
  /* '<S15>:1:3' */
  /* '<S15>:1:5' */
  tmp_2[0] = (0.6555 - 0.3545 * ctrl_student_HIL_B.Integrator[3]) -
    ctrl_student_HIL_B.Integrator[3] * ctrl_student_HIL_B.Integrator[3] * -3.787;
  tmp_2[3] = (-0.0 - -2.443 * ctrl_student_HIL_B.Integrator[4]) -
    ctrl_student_HIL_B.Integrator[4] * ctrl_student_HIL_B.Integrator[4] * 0.0;
  tmp_2[6] = 0.0;
  tmp_2[1] = 0.0;
  tmp_2[4] = ((1.33 - -2.776 * ctrl_student_HIL_B.Integrator[4]) -
              ctrl_student_HIL_B.Integrator[4] * ctrl_student_HIL_B.Integrator[4]
              * -64.91) - -0.805 * fabs(ctrl_student_HIL_B.Integrator[5]);
  tmp_2[7] = ((7.25 - -3.45 * fabs(ctrl_student_HIL_B.Integrator[5])) -
              ctrl_student_HIL_B.Integrator[5] * ctrl_student_HIL_B.Integrator[5]
              * 0.0) - -0.845 * fabs(ctrl_student_HIL_B.Integrator[4]);
  tmp_2[2] = 0.0;
  tmp_2[5] = ((-0.0 - -0.2088 * ctrl_student_HIL_B.Integrator[4]) -
              ctrl_student_HIL_B.Integrator[4] * ctrl_student_HIL_B.Integrator[4]
              * 0.0) - 0.13 * fabs(ctrl_student_HIL_B.Integrator[5]);
  tmp_2[8] = ((1.9 - -0.75 * fabs(ctrl_student_HIL_B.Integrator[5])) -
              ctrl_student_HIL_B.Integrator[5] * ctrl_student_HIL_B.Integrator[5]
              * 0.0) - 0.08 * fabs(ctrl_student_HIL_B.Integrator[4]);

  /* MATLAB Function: '<S10>/z_1_dot' */
  tmp_3[0] = 0.0;
  tmp_3[3] = -ctrl_student_HIL_B.Integrator[5];
  tmp_3[6] = 0.0;
  tmp_3[1] = ctrl_student_HIL_B.Integrator[5];
  tmp_3[4] = 0.0;
  tmp_3[7] = 0.0;
  tmp_3[2] = 0.0;
  tmp_3[5] = 0.0;
  tmp_3[8] = 0.0;
  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp[3 * ixstart] = -tmp_3[3 * ixstart];
    tmp[1 + 3 * ixstart] = -tmp_3[3 * ixstart + 1];
    tmp[2 + 3 * ixstart] = -tmp_3[3 * ixstart + 2];
  }

  tmp_4[0] = cos(ctrl_student_HIL_B.Integrator[2]);
  tmp_4[1] = -sin(ctrl_student_HIL_B.Integrator[2]);
  tmp_4[2] = 0.0;
  tmp_4[3] = sin(ctrl_student_HIL_B.Integrator[2]);
  tmp_4[4] = cos(ctrl_student_HIL_B.Integrator[2]);
  tmp_4[5] = 0.0;
  tmp_4[6] = 0.0;
  tmp_4[7] = 0.0;
  tmp_4[8] = 1.0;
  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_1[ixstart] = tmp_4[ixstart + 6] * ctrl_student_HIL_B.Switch_j[5] +
      (tmp_4[ixstart + 3] * ctrl_student_HIL_B.Switch_j[4] + tmp_4[ixstart] *
       ctrl_student_HIL_B.Switch_j[3]);
  }

  /* MATLAB Function: '<S10>/alfa1_dot' */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_0[3 * ixstart] = -ctrl_student_HIL_B.K_p[3 * ixstart];
    tmp_0[1 + 3 * ixstart] = -ctrl_student_HIL_B.K_p[3 * ixstart + 1];
    tmp_0[2 + 3 * ixstart] = -ctrl_student_HIL_B.K_p[3 * ixstart + 2];
  }

  /* MATLAB Function: '<S10>/z_1_dot' incorporates:
   *  MATLAB Function: '<S10>/alfa1_dot'
   */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_5[ixstart] = (((tmp[ixstart + 3] * rtb_z_1[1] + tmp[ixstart] * rtb_z_1[0])
                       + tmp[ixstart + 6] * rtb_z_1[2]) +
                      ctrl_student_HIL_B.Integrator[3 + ixstart]) -
      tmp_1[ixstart] * ctrl_student_HIL_B.s_dot;
  }

  /* MATLAB Function: '<S10>/alfa1_dot' incorporates:
   *  MATLAB Function: '<S10>/tau'
   */
  tmp_6[0] = 0.0;
  tmp_6[3] = -ctrl_student_HIL_B.Integrator[5];
  tmp_6[6] = 0.0;
  tmp_6[1] = 0.0;
  tmp_6[4] = ctrl_student_HIL_B.Integrator[5];
  tmp_6[7] = 0.0;
  tmp_6[2] = 0.0;
  tmp_6[5] = 0.0;
  tmp_6[8] = 0.0;
  for (ixstart = 0; ixstart < 3; ixstart++) {
    for (i = 0; i < 3; i++) {
      tmp[ixstart + 3 * i] = 0.0;
      tmp[ixstart + 3 * i] += 0.0 * R[i];
      tmp[ixstart + 3 * i] += tmp_6[ixstart + 3] * R[i + 3];
    }
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_1[ixstart] = tmp[ixstart + 6] * ctrl_student_HIL_B.Switch_j[5] +
      (tmp[ixstart + 3] * ctrl_student_HIL_B.Switch_j[4] + tmp[ixstart] *
       ctrl_student_HIL_B.Switch_j[3]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    R_0[ixstart] = R[3 * ixstart + 2] * ctrl_student_HIL_B.Switch_j[8] + (R[3 *
      ixstart + 1] * ctrl_student_HIL_B.Switch_j[7] + R[3 * ixstart] *
      ctrl_student_HIL_B.Switch_j[6]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tau_NED[ixstart] = R[3 * ixstart + 2] * ctrl_student_HIL_B.Switch_j[5] + (R
      [3 * ixstart + 1] * ctrl_student_HIL_B.Switch_j[4] + R[3 * ixstart] *
      ctrl_student_HIL_B.Switch_j[3]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_7[ixstart] = ((((tmp_0[ixstart + 3] * tmp_5[1] + tmp_0[ixstart] * tmp_5
                         [0]) + tmp_0[ixstart + 6] * tmp_5[2]) - tmp_1[ixstart] *
                       ctrl_student_HIL_B.U_s) + R_0[ixstart] *
                      ctrl_student_HIL_B.s_dot * ctrl_student_HIL_B.U_s) +
      tau_NED[ixstart] * ctrl_student_HIL_B.Derivative;
  }

  /* MATLAB Function: '<S10>/tau' incorporates:
   *  Constant: '<S10>/Constant'
   *  MATLAB Function: '<S10>/z_2'
   */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    tau_NED[ixstart] = (-rtb_z_1[ixstart] - (ctrl_student_HIL_B.Integrator[3 +
      ixstart] - ctrl_student_HIL_B.alfa1[ixstart]) * ctrl_student_HIL_B.C_2) +
      ((tmp_2[ixstart + 3] * ctrl_student_HIL_B.Integrator[4] + tmp_2[ixstart] *
        ctrl_student_HIL_B.Integrator[3]) + tmp_2[ixstart + 6] *
       ctrl_student_HIL_B.Integrator[5]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_1[ixstart] = ctrl_student_HIL_P.Par.Guidance.M[ixstart + 6] * tmp_7[2] +
      (ctrl_student_HIL_P.Par.Guidance.M[ixstart + 3] * tmp_7[1] +
       ctrl_student_HIL_P.Par.Guidance.M[ixstart] * tmp_7[0]);
  }

  tmp_8[0] = cos(ctrl_student_HIL_B.Integrator[2]);
  tmp_8[1] = -sin(ctrl_student_HIL_B.Integrator[2]);
  tmp_8[2] = 0.0;
  tmp_8[3] = sin(ctrl_student_HIL_B.Integrator[2]);
  tmp_8[4] = cos(ctrl_student_HIL_B.Integrator[2]);
  tmp_8[5] = 0.0;
  tmp_8[6] = 0.0;
  tmp_8[7] = 0.0;
  tmp_8[8] = 1.0;
  for (ixstart = 0; ixstart < 3; ixstart++) {
    ctrl_student_HIL_B.tau[ixstart] = (tau_NED[ixstart] + tmp_1[ixstart]) -
      ((tmp_8[ixstart + 3] * ctrl_student_HIL_B.Integrator[7] + tmp_8[ixstart] *
        ctrl_student_HIL_B.Integrator[6]) + tmp_8[ixstart + 6] *
       ctrl_student_HIL_B.Integrator[8]);
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   */
  if (ctrl_student_HIL_B.Enable_controller != 0.0) {
    rtb_z_1[0] = ctrl_student_HIL_B.tau[0];
    rtb_z_1[1] = ctrl_student_HIL_B.tau[1];
    rtb_z_1[2] = ctrl_student_HIL_B.tau[2];
  } else {
    rtb_z_1[0] = 0.25 * ctrl_student_HIL_P.Par.Thrust_lim[0] *
      (ctrl_student_HIL_P.Gain_Gain * ctrl_student_HIL_B.PosYRight);
    rtb_z_1[1] = 0.25 * ctrl_student_HIL_P.Par.Thrust_lim[1] *
      ctrl_student_HIL_B.PosXRight;
    rtb_z_1[2] = 0.25 * ctrl_student_HIL_P.Par.Thrust_lim[2] *
      ctrl_student_HIL_B.PosXLeft;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/Constant4'
   *  Constant: '<S7>/Constant5'
   *  Saturate: '<S7>/Saturation'
   */
  /* MATLAB Function 'Workspace saturation1/MATLAB Function': '<S45>:1' */
  /* '<S45>:1:3' */
  R[0] = cos(ctrl_student_HIL_B.Switch_m[2]);
  R[3] = sin(ctrl_student_HIL_B.Switch_m[2]);
  R[6] = 0.0;
  R[1] = -sin(ctrl_student_HIL_B.Switch_m[2]);
  R[4] = cos(ctrl_student_HIL_B.Switch_m[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* '<S45>:1:5' */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    tau_NED[ixstart] = R[ixstart + 6] * rtb_z_1[2] + (R[ixstart + 3] * rtb_z_1[1]
      + R[ixstart] * rtb_z_1[0]);
  }

  /* '<S45>:1:6' */
  rtb_z_1[0] = tau_NED[0];
  rtb_z_1[1] = tau_NED[1];

  /* check if x is above limits */
  if (ctrl_student_HIL_B.Switch_m[0] > ctrl_student_HIL_P.Par.Workspace.x_max) {
    /* '<S45>:1:9' */
    /* x is above of the limit */
    /* '<S45>:1:11' */
    N = (ctrl_student_HIL_B.Switch_m[0] - ctrl_student_HIL_P.Par.Workspace.x_max)
      * ctrl_student_HIL_P.Par.Workspace.scale /
      ctrl_student_HIL_P.Par.Workspace.threshold;

    /* '<S45>:1:12' */
    rtb_z_1[0] = (1.0 - N) * tau_NED[0] + -N;
  }

  /* check if x is below limits */
  if (ctrl_student_HIL_B.Switch_m[0] < ctrl_student_HIL_P.Par.Workspace.x_min) {
    /* '<S45>:1:15' */
    /* x is below of the limit */
    /* '<S45>:1:17' */
    N = (ctrl_student_HIL_B.Switch_m[0] - ctrl_student_HIL_P.Par.Workspace.x_min)
      * ctrl_student_HIL_P.Par.Workspace.scale /
      ctrl_student_HIL_P.Par.Workspace.threshold;

    /* '<S45>:1:18' */
    rtb_z_1[0] = (1.0 + N) * tau_NED[0] + -N;
  }

  /* check if y is above limits */
  if (ctrl_student_HIL_B.Switch_m[1] > ctrl_student_HIL_P.Par.Workspace.y_max) {
    /* '<S45>:1:21' */
    /* x is above of the limit */
    /* '<S45>:1:23' */
    N = (ctrl_student_HIL_B.Switch_m[1] - ctrl_student_HIL_P.Par.Workspace.y_max)
      * ctrl_student_HIL_P.Par.Workspace.scale /
      ctrl_student_HIL_P.Par.Workspace.threshold;

    /* '<S45>:1:24' */
    rtb_z_1[1] = (1.0 - N) * tau_NED[1] + -N;
  }

  /* check if y is above limits */
  if (ctrl_student_HIL_B.Switch_m[1] < ctrl_student_HIL_P.Par.Workspace.y_min) {
    /* '<S45>:1:27' */
    /* x is above of the limit */
    /* '<S45>:1:29' */
    N = (ctrl_student_HIL_B.Switch_m[1] - ctrl_student_HIL_P.Par.Workspace.y_min)
      * ctrl_student_HIL_P.Par.Workspace.scale /
      ctrl_student_HIL_P.Par.Workspace.threshold;

    /* '<S45>:1:30' */
    rtb_z_1[1] = (1.0 + N) * tau_NED[1] + -N;
  }

  /* '<S45>:1:32' */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    R_0[ixstart] = R[3 * ixstart + 2] * tau_NED[2] + (R[3 * ixstart + 1] *
      rtb_z_1[1] + R[3 * ixstart] * rtb_z_1[0]);
  }

  /* Saturate: '<S7>/Saturation' incorporates:
   *  MATLAB Function: '<S7>/MATLAB Function'
   */
  if (R_0[0] > ctrl_student_HIL_P.Saturation_UpperSat[0]) {
    ctrl_student_HIL_B.Saturation[0] = ctrl_student_HIL_P.Saturation_UpperSat[0];
  } else if (R_0[0] < ctrl_student_HIL_P.Saturation_LowerSat[0]) {
    ctrl_student_HIL_B.Saturation[0] = ctrl_student_HIL_P.Saturation_LowerSat[0];
  } else {
    ctrl_student_HIL_B.Saturation[0] = R_0[0];
  }

  if (R_0[1] > ctrl_student_HIL_P.Saturation_UpperSat[1]) {
    ctrl_student_HIL_B.Saturation[1] = ctrl_student_HIL_P.Saturation_UpperSat[1];
  } else if (R_0[1] < ctrl_student_HIL_P.Saturation_LowerSat[1]) {
    ctrl_student_HIL_B.Saturation[1] = ctrl_student_HIL_P.Saturation_LowerSat[1];
  } else {
    ctrl_student_HIL_B.Saturation[1] = R_0[1];
  }

  if (R_0[2] > ctrl_student_HIL_P.Saturation_UpperSat[2]) {
    ctrl_student_HIL_B.Saturation[2] = ctrl_student_HIL_P.Saturation_UpperSat[2];
  } else if (R_0[2] < ctrl_student_HIL_P.Saturation_LowerSat[2]) {
    ctrl_student_HIL_B.Saturation[2] = ctrl_student_HIL_P.Saturation_LowerSat[2];
  } else {
    ctrl_student_HIL_B.Saturation[2] = R_0[2];
  }

  /* SignalConversion: '<Root>/TmpSignal ConversionAtnuInport1' */
  ctrl_student_HIL_B.nu[0] = ctrl_student_HIL_B.u_in;
  ctrl_student_HIL_B.nu[1] = ctrl_student_HIL_B.v_in;
  ctrl_student_HIL_B.nu[2] = ctrl_student_HIL_B.r_in;

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  Constant: '<S6>/Inverse of T'
   */
  /* MATLAB Function 'Thrust Allocation/MATLAB Function': '<S44>:1' */
  /* '<S44>:1:4' */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    rtb_z_1[ixstart] = ctrl_student_HIL_P.InverseofT_Value[ixstart + 6] *
      ctrl_student_HIL_B.Saturation[2] +
      (ctrl_student_HIL_P.InverseofT_Value[ixstart + 3] *
       ctrl_student_HIL_B.Saturation[1] +
       ctrl_student_HIL_P.InverseofT_Value[ixstart] *
       ctrl_student_HIL_B.Saturation[0]);
  }

  /* End of MATLAB Function: '<S6>/MATLAB Function' */

  /* MATLAB Function: '<S5>/MATLAB Function1' */
  /* MATLAB Function 'Sixaxis2force/MATLAB Function1': '<S43>:1' */
  /* '<S43>:1:2' */
  N = sqrt(rtb_z_1[0] * rtb_z_1[0] + rtb_z_1[1] * rtb_z_1[1]);
  ixstart = 1;
  if (rtIsNaN(N)) {
    ixstart = 2;
    N = 1.0;
  }

  if ((ixstart < 2) && (1.0 < N)) {
    N = 1.0;
  }

  ctrl_student_HIL_B.u_VSP = N;

  /* '<S43>:1:3' */
  ctrl_student_HIL_B.alpha_VSP = rt_atan2d_snf(rtb_z_1[1], rtb_z_1[0]);

  /* '<S43>:1:4' */
  ctrl_student_HIL_B.u_BT = rtb_z_1[2];

  /* End of MATLAB Function: '<S5>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */
    memcpy(&rtb_TmpSignalConversionAtToFile[0], &ctrl_student_HIL_B.Integrator[0],
           9U * sizeof(real_T));
    rtb_TmpSignalConversionAtToFile[9] = ctrl_student_HIL_B.x_in;
    rtb_TmpSignalConversionAtToFile[10] = ctrl_student_HIL_B.y_in;
    rtb_TmpSignalConversionAtToFile[11] = ctrl_student_HIL_B.psi_in;
    rtb_TmpSignalConversionAtToFile[12] = ctrl_student_HIL_B.Switch_m[0];
    rtb_TmpSignalConversionAtToFile[13] = ctrl_student_HIL_B.Switch_m[1];
    rtb_TmpSignalConversionAtToFile[14] = ctrl_student_HIL_B.Switch_m[2];
    rtb_TmpSignalConversionAtToFile[15] = ctrl_student_HIL_B.u_in;
    rtb_TmpSignalConversionAtToFile[16] = ctrl_student_HIL_B.v_in;
    rtb_TmpSignalConversionAtToFile[17] = ctrl_student_HIL_B.r_in;
    rtb_TmpSignalConversionAtToFile[18] = ctrl_student_HIL_B.tau[0];
    rtb_TmpSignalConversionAtToFile[19] = ctrl_student_HIL_B.tau[1];
    rtb_TmpSignalConversionAtToFile[20] = ctrl_student_HIL_B.tau[2];
    rtb_TmpSignalConversionAtToFile[21] = ctrl_student_HIL_B.Switch_j[0];
    rtb_TmpSignalConversionAtToFile[22] = ctrl_student_HIL_B.Switch_j[1];
    rtb_TmpSignalConversionAtToFile[23] = ctrl_student_HIL_B.Switch_j[2];
    rtb_TmpSignalConversionAtToFile[24] = ctrl_student_HIL_B.alfa1[0];
    rtb_TmpSignalConversionAtToFile[25] = ctrl_student_HIL_B.alfa1[1];
    rtb_TmpSignalConversionAtToFile[26] = ctrl_student_HIL_B.alfa1[2];

    /* ToFile: '<Root>/To File' */
    {
      if (!(++ctrl_student_HIL_DW.ToFile_IWORK.Decimation % 1) &&
          (ctrl_student_HIL_DW.ToFile_IWORK.Count*28)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_student_HIL_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[28];
          ctrl_student_HIL_DW.ToFile_IWORK.Decimation = 0;
          u[0] = ctrl_student_HIL_M->Timing.t[1];
          u[1] = rtb_TmpSignalConversionAtToFile[0];
          u[2] = rtb_TmpSignalConversionAtToFile[1];
          u[3] = rtb_TmpSignalConversionAtToFile[2];
          u[4] = rtb_TmpSignalConversionAtToFile[3];
          u[5] = rtb_TmpSignalConversionAtToFile[4];
          u[6] = rtb_TmpSignalConversionAtToFile[5];
          u[7] = rtb_TmpSignalConversionAtToFile[6];
          u[8] = rtb_TmpSignalConversionAtToFile[7];
          u[9] = rtb_TmpSignalConversionAtToFile[8];
          u[10] = rtb_TmpSignalConversionAtToFile[9];
          u[11] = rtb_TmpSignalConversionAtToFile[10];
          u[12] = rtb_TmpSignalConversionAtToFile[11];
          u[13] = rtb_TmpSignalConversionAtToFile[12];
          u[14] = rtb_TmpSignalConversionAtToFile[13];
          u[15] = rtb_TmpSignalConversionAtToFile[14];
          u[16] = rtb_TmpSignalConversionAtToFile[15];
          u[17] = rtb_TmpSignalConversionAtToFile[16];
          u[18] = rtb_TmpSignalConversionAtToFile[17];
          u[19] = rtb_TmpSignalConversionAtToFile[18];
          u[20] = rtb_TmpSignalConversionAtToFile[19];
          u[21] = rtb_TmpSignalConversionAtToFile[20];
          u[22] = rtb_TmpSignalConversionAtToFile[21];
          u[23] = rtb_TmpSignalConversionAtToFile[22];
          u[24] = rtb_TmpSignalConversionAtToFile[23];
          u[25] = rtb_TmpSignalConversionAtToFile[24];
          u[26] = rtb_TmpSignalConversionAtToFile[25];
          u[27] = rtb_TmpSignalConversionAtToFile[26];
          if (fwrite(u, sizeof(real_T), 28, fp) != 28) {
            rtmSetErrorStatus(ctrl_student_HIL_M,
                              "Error writing to MAT-file log.mat");
            return;
          }

          if (((++ctrl_student_HIL_DW.ToFile_IWORK.Count)*28)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file log.mat.\n");
          }
        }
      }
    }
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* MATLAB Function: '<S2>/Observer' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   */
  /* MATLAB Function 'Luenberger Observer/Observer': '<S22>:1' */
  /* Rotation matrix */
  /* '<S22>:1:5' */
  R[0] = cos(ctrl_student_HIL_B.Switch_m[2]);
  R[3] = -sin(ctrl_student_HIL_B.Switch_m[2]);
  R[6] = 0.0;
  R[1] = sin(ctrl_student_HIL_B.Switch_m[2]);
  R[4] = cos(ctrl_student_HIL_B.Switch_m[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* % eta bar */
  /* '<S22>:1:9' */
  /* '<S22>:1:10' */
  rtb_z_1[0] = ctrl_student_HIL_B.Switch_m[0] - ctrl_student_HIL_B.Integrator[0];
  rtb_z_1[1] = ctrl_student_HIL_B.Switch_m[1] - ctrl_student_HIL_B.Integrator[1];
  rtb_z_1[2] = ctrl_student_HIL_B.Switch_m[2] - ctrl_student_HIL_B.Integrator[2];

  /* '<S22>:1:12' */
  /* '<S22>:1:13' */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S22>:1:16' */
  /* '<S22>:1:20' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S22>:1:26' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Assembly of the damping matrix */
  /* '<S22>:1:32' */
  /* '<S22>:1:33' */
  /* '<S22>:1:34' */
  /*  using abs(r) */
  /* '<S22>:1:36' */
  /* '<S22>:1:37' */
  /* '<S22>:1:38' */
  /* '<S22>:1:40' */
  /* % x_dot equations */
  /* '<S22>:1:46' */
  /* nu_hat_dot = M_inv*(-D*nu_hat + R'*(b_hat + L_2*eta_bar) + tau); */
  /* '<S22>:1:48' */
  /* '<S22>:1:49' */
  /* '<S22>:1:51' */
  for (ixstart = 0; ixstart < 3; ixstart++) {
    R_0[ixstart] = R[ixstart + 6] * ctrl_student_HIL_B.Integrator[5] +
      (R[ixstart + 3] * ctrl_student_HIL_B.Integrator[4] + R[ixstart] *
       ctrl_student_HIL_B.Integrator[3]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_1[ixstart] = ctrl_student_HIL_P.Constant_Value_m[ixstart + 6] * rtb_z_1
      [2] + (ctrl_student_HIL_P.Constant_Value_m[ixstart + 3] * rtb_z_1[1] +
             ctrl_student_HIL_P.Constant_Value_m[ixstart] * rtb_z_1[0]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp[3 * ixstart] = -ctrl_student_HIL_P.Par.Observer.M_inv[3 * ixstart];
    tmp[1 + 3 * ixstart] = -ctrl_student_HIL_P.Par.Observer.M_inv[3 * ixstart +
      1];
    tmp[2 + 3 * ixstart] = -ctrl_student_HIL_P.Par.Observer.M_inv[3 * ixstart +
      2];
  }

  tmp_9[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_B.Integrator[3])) -
    ctrl_student_HIL_B.Integrator[3] * ctrl_student_HIL_B.Integrator[3] * -3.787;
  tmp_9[3] = (-0.0 - -2.443 * fabs(ctrl_student_HIL_B.Integrator[4])) -
    ctrl_student_HIL_B.Integrator[4] * ctrl_student_HIL_B.Integrator[4] * 0.0;
  tmp_9[6] = 0.0;
  tmp_9[1] = 0.0;
  tmp_9[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_B.Integrator[4])) -
              ctrl_student_HIL_B.Integrator[4] * ctrl_student_HIL_B.Integrator[4]
              * -64.91) - -0.805 * fabs(ctrl_student_HIL_B.Integrator[5]);
  tmp_9[7] = ((7.25 - -3.45 * fabs(ctrl_student_HIL_B.Integrator[5])) -
              ctrl_student_HIL_B.Integrator[5] * ctrl_student_HIL_B.Integrator[5]
              * 0.0) - -0.845 * fabs(ctrl_student_HIL_B.Integrator[4]);
  tmp_9[2] = 0.0;
  tmp_9[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_B.Integrator[4])) -
              ctrl_student_HIL_B.Integrator[4] * ctrl_student_HIL_B.Integrator[4]
              * 0.0) - 0.13 * fabs(ctrl_student_HIL_B.Integrator[5]);
  tmp_9[8] = ((1.9 - -0.75 * fabs(ctrl_student_HIL_B.Integrator[5])) -
              ctrl_student_HIL_B.Integrator[5] * ctrl_student_HIL_B.Integrator[5]
              * 0.0) - 0.08 * fabs(ctrl_student_HIL_B.Integrator[4]);
  for (ixstart = 0; ixstart < 3; ixstart++) {
    for (i = 0; i < 3; i++) {
      tmp_0[ixstart + 3 * i] = 0.0;
      tmp_0[ixstart + 3 * i] += tmp_9[3 * i] * tmp[ixstart];
      tmp_0[ixstart + 3 * i] += tmp_9[3 * i + 1] * tmp[ixstart + 3];
      tmp_0[ixstart + 3 * i] += tmp_9[3 * i + 2] * tmp[ixstart + 6];
    }
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    for (i = 0; i < 3; i++) {
      tmp[ixstart + 3 * i] = 0.0;
      tmp[ixstart + 3 * i] += ctrl_student_HIL_P.Par.Observer.M_inv[ixstart] *
        R[i];
      tmp[ixstart + 3 * i] += ctrl_student_HIL_P.Par.Observer.M_inv[ixstart + 3]
        * R[i + 3];
      tmp[ixstart + 3 * i] += ctrl_student_HIL_P.Par.Observer.M_inv[ixstart + 6]
        * R[i + 6];
    }
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_5[ixstart] = tmp_0[ixstart + 6] * ctrl_student_HIL_B.Integrator[5] +
      (tmp_0[ixstart + 3] * ctrl_student_HIL_B.Integrator[4] + tmp_0[ixstart] *
       ctrl_student_HIL_B.Integrator[3]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_7[ixstart] = tmp[ixstart + 6] * ctrl_student_HIL_B.Integrator[8] +
      (tmp[ixstart + 3] * ctrl_student_HIL_B.Integrator[7] + tmp[ixstart] *
       ctrl_student_HIL_B.Integrator[6]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    for (i = 0; i < 3; i++) {
      tmp[ixstart + 3 * i] = 0.0;
      tmp[ixstart + 3 * i] += ctrl_student_HIL_P.Par.Observer.M_inv[ixstart] *
        R[i];
      tmp[ixstart + 3 * i] += ctrl_student_HIL_P.Par.Observer.M_inv[ixstart + 3]
        * R[i + 3];
      tmp[ixstart + 3 * i] += ctrl_student_HIL_P.Par.Observer.M_inv[ixstart + 6]
        * R[i + 6];
    }
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    for (i = 0; i < 3; i++) {
      tmp_0[ixstart + 3 * i] = 0.0;
      tmp_0[ixstart + 3 * i] += ctrl_student_HIL_B.L_2[3 * i] * tmp[ixstart];
      tmp_0[ixstart + 3 * i] += ctrl_student_HIL_B.L_2[3 * i + 1] * tmp[ixstart
        + 3];
      tmp_0[ixstart + 3 * i] += ctrl_student_HIL_B.L_2[3 * i + 2] * tmp[ixstart
        + 6];
    }
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tau_NED[ixstart] = ((tmp_0[ixstart + 3] * rtb_z_1[1] + tmp_0[ixstart] *
                         rtb_z_1[0]) + tmp_0[ixstart + 6] * rtb_z_1[2]) +
      (tmp_5[ixstart] + tmp_7[ixstart]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_5[ixstart] = ctrl_student_HIL_P.Par.Observer.M_inv[ixstart + 6] *
      ctrl_student_HIL_B.Saturation[2] +
      (ctrl_student_HIL_P.Par.Observer.M_inv[ixstart + 3] *
       ctrl_student_HIL_B.Saturation[1] +
       ctrl_student_HIL_P.Par.Observer.M_inv[ixstart] *
       ctrl_student_HIL_B.Saturation[0]);
  }

  for (ixstart = 0; ixstart < 3; ixstart++) {
    tmp_7[ixstart] = ctrl_student_HIL_P.Constant3_Value[ixstart + 6] * rtb_z_1[2]
      + (ctrl_student_HIL_P.Constant3_Value[ixstart + 3] * rtb_z_1[1] +
         ctrl_student_HIL_P.Constant3_Value[ixstart] * rtb_z_1[0]);
  }

  ctrl_student_HIL_B.x_hat_dot[0] = R_0[0] + tmp_1[0];
  ctrl_student_HIL_B.x_hat_dot[1] = R_0[1] + tmp_1[1];
  ctrl_student_HIL_B.x_hat_dot[2] = R_0[2] + tmp_1[2];
  ctrl_student_HIL_B.x_hat_dot[3] = tau_NED[0] + tmp_5[0];
  ctrl_student_HIL_B.x_hat_dot[4] = tau_NED[1] + tmp_5[1];
  ctrl_student_HIL_B.x_hat_dot[5] = tau_NED[2] + tmp_5[2];
  ctrl_student_HIL_B.x_hat_dot[6] = tmp_7[0];
  ctrl_student_HIL_B.x_hat_dot[7] = tmp_7[1];
  ctrl_student_HIL_B.x_hat_dot[8] = tmp_7[2];

  /* End of MATLAB Function: '<S2>/Observer' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* MATLAB Function: '<S4>/Detect droput' */
  /* MATLAB Function 'Signal Dropout detection/Detect droput': '<S39>:1' */
  if (!ctrl_student_HIL_DW.eta_old_not_empty) {
    /* '<S39>:1:3' */
    /* '<S39>:1:4' */
    ctrl_student_HIL_DW.eta_old[0] = 0.0;
    ctrl_student_HIL_DW.eta_old[1] = 0.0;
    ctrl_student_HIL_DW.eta_old[2] = 0.0;
    ctrl_student_HIL_DW.eta_old_not_empty = true;
  }

  /* '<S39>:1:6' */
  /* '<S39>:1:7' */
  ctrl_student_HIL_B.dropout[0] = (0.0 - ctrl_student_HIL_DW.eta_old[0] == 0.0);
  ctrl_student_HIL_B.dropout[1] = (0.0 - ctrl_student_HIL_DW.eta_old[1] == 0.0);
  ctrl_student_HIL_B.dropout[2] = (0.0 - ctrl_student_HIL_DW.eta_old[2] == 0.0);

  /* '<S39>:1:8' */
  /* '<S39>:1:13' */
  ctrl_student_HIL_DW.eta_old[0] = 0.0;
  ctrl_student_HIL_DW.eta_old[1] = 0.0;
  ctrl_student_HIL_DW.eta_old[2] = 0.0;

  /* End of MATLAB Function: '<S4>/Detect droput' */

  /* Integrator: '<S40>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = ((ZCEventType) (ctrl_student_HIL_B.dropout[2] &&
                (ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_g != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_g = (ZCSigState)
      ctrl_student_HIL_B.dropout[2];
    if (zcEvent || ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator_CSTATE_n = ctrl_student_HIL_B.r_in;
    }
  }

  rtb_Integrator = ctrl_student_HIL_X.Integrator_CSTATE_n;

  /* Integrator: '<S41>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = ((ZCEventType) (ctrl_student_HIL_B.dropout[0] &&
                (ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_i != POS_ZCSIG)));

    /* evaluate zero-crossings */
    ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_i = (ZCSigState)
      ctrl_student_HIL_B.dropout[0];
    if (zcEvent || ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator_CSTATE_l = 0.0;
    }
  }

  rtb_Integrator_i = ctrl_student_HIL_X.Integrator_CSTATE_l;

  /* Integrator: '<S42>/Integrator' */
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

  rtb_Integrator_ib = ctrl_student_HIL_X.Integrator_CSTATE_m;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  real_T *lastU;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S31>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_B.count;

    /* Update for RandomNumber: '<S37>/White Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S38>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_m = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_l) * ctrl_student_HIL_P.WhiteNoise_StdDev_k
      + ctrl_student_HIL_P.WhiteNoise_Mean_p;

    /* Update for RandomNumber: '<S36>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_k) * ctrl_student_HIL_P.WhiteNoise_StdDev_i
      + ctrl_student_HIL_P.WhiteNoise_Mean_k;

    /* Update for Memory: '<S32>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_B.output[2];

    /* Update for RandomNumber: '<S25>/Random Number' */
    ctrl_student_HIL_DW.NextOutput_o = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_e) * ctrl_student_HIL_P.RandomNumber_StdDev
      + ctrl_student_HIL_P.RandomNumber_Mean;

    /* Update for RandomNumber: '<S26>/Random Number' */
    ctrl_student_HIL_DW.NextOutput_os = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_n) *
      ctrl_student_HIL_P.RandomNumber_StdDev_d +
      ctrl_student_HIL_P.RandomNumber_Mean_p;

    /* Update for RandomNumber: '<S27>/Random Number' */
    ctrl_student_HIL_DW.NextOutput_e = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_m) *
      ctrl_student_HIL_P.RandomNumber_StdDev_c +
      ctrl_student_HIL_P.RandomNumber_Mean_h;
  }

  /* Update for Derivative: '<S10>/Derivative' */
  if (ctrl_student_HIL_DW.TimeStampA == (rtInf)) {
    ctrl_student_HIL_DW.TimeStampA = ctrl_student_HIL_M->Timing.t[0];
    lastU = &ctrl_student_HIL_DW.LastUAtTimeA;
  } else if (ctrl_student_HIL_DW.TimeStampB == (rtInf)) {
    ctrl_student_HIL_DW.TimeStampB = ctrl_student_HIL_M->Timing.t[0];
    lastU = &ctrl_student_HIL_DW.LastUAtTimeB;
  } else if (ctrl_student_HIL_DW.TimeStampA < ctrl_student_HIL_DW.TimeStampB) {
    ctrl_student_HIL_DW.TimeStampA = ctrl_student_HIL_M->Timing.t[0];
    lastU = &ctrl_student_HIL_DW.LastUAtTimeA;
  } else {
    ctrl_student_HIL_DW.TimeStampB = ctrl_student_HIL_M->Timing.t[0];
    lastU = &ctrl_student_HIL_DW.LastUAtTimeB;
  }

  *lastU = ctrl_student_HIL_B.U_s;

  /* End of Update for Derivative: '<S10>/Derivative' */
  /* Update for Integrator: '<S40>/Integrator' */
  ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 0;

  /* Update for Integrator: '<S41>/Integrator' */
  ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading = 0;

  /* Update for Integrator: '<S42>/Integrator' */
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
  /* Derivatives for Integrator: '<S2>/Integrator' */
  {
    {
      int_T i1;
      const real_T *u0 = &ctrl_student_HIL_B.x_hat_dot[0];
      real_T *xdot = &((XDot_ctrl_student_HIL_T *)
                       ctrl_student_HIL_M->ModelData.derivs)->Integrator_CSTATE
        [0];
      for (i1=0; i1 < 9; i1++) {
        xdot[i1] = u0[i1];
      }
    }
  }

  /* Derivatives for Integrator: '<S11>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE = ctrl_student_HIL_B.s_dot;
  }

  /* Derivatives for Integrator: '<S40>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_n = 0.0;
  }

  /* Derivatives for Integrator: '<S41>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_l = ctrl_student_HIL_B.u_in;
  }

  /* Derivatives for Integrator: '<S42>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE_m = 0.0;
  }
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "log.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_student_HIL_M, "Error creating .mat file log.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,28,0,"x")) {
      rtmSetErrorStatus(ctrl_student_HIL_M,
                        "Error writing mat file header to file log.mat");
      return;
    }

    ctrl_student_HIL_DW.ToFile_IWORK.Count = 0;
    ctrl_student_HIL_DW.ToFile_IWORK.Decimation = -1;
    ctrl_student_HIL_DW.ToFile_PWORK.FilePtr = fp;
  }

  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Memory: '<S31>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S37>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed);
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
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S37>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S38>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_m);
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

    ctrl_student_HIL_DW.RandSeed_l = tseed;
    ctrl_student_HIL_DW.NextOutput_m = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_l) * ctrl_student_HIL_P.WhiteNoise_StdDev_k
      + ctrl_student_HIL_P.WhiteNoise_Mean_p;

    /* End of InitializeConditions for RandomNumber: '<S38>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S36>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_h);
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

    ctrl_student_HIL_DW.RandSeed_k = tseed;
    ctrl_student_HIL_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_k) * ctrl_student_HIL_P.WhiteNoise_StdDev_i
      + ctrl_student_HIL_P.WhiteNoise_Mean_k;

    /* End of InitializeConditions for RandomNumber: '<S36>/White Noise' */

    /* InitializeConditions for Memory: '<S32>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_P.Hold_X0;

    /* InitializeConditions for RandomNumber: '<S25>/Random Number' */
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

    ctrl_student_HIL_DW.RandSeed_e = tseed;
    ctrl_student_HIL_DW.NextOutput_o = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_e) * ctrl_student_HIL_P.RandomNumber_StdDev
      + ctrl_student_HIL_P.RandomNumber_Mean;

    /* End of InitializeConditions for RandomNumber: '<S25>/Random Number' */

    /* InitializeConditions for MATLAB Function: '<S25>/Freeze signal' */
    ctrl_student__Freezesignal_Init(&ctrl_student_HIL_DW.sf_Freezesignal);

    /* InitializeConditions for RandomNumber: '<S26>/Random Number' */
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

    ctrl_student_HIL_DW.RandSeed_n = tseed;
    ctrl_student_HIL_DW.NextOutput_os = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_n) *
      ctrl_student_HIL_P.RandomNumber_StdDev_d +
      ctrl_student_HIL_P.RandomNumber_Mean_p;

    /* End of InitializeConditions for RandomNumber: '<S26>/Random Number' */

    /* InitializeConditions for MATLAB Function: '<S26>/Freeze signal' */
    ctrl_student__Freezesignal_Init(&ctrl_student_HIL_DW.sf_Freezesignal_k);

    /* InitializeConditions for RandomNumber: '<S27>/Random Number' */
    tmp = floor(ctrl_student_HIL_P.RandomNumber_Seed_o);
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

    ctrl_student_HIL_DW.RandSeed_m = tseed;
    ctrl_student_HIL_DW.NextOutput_e = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_m) *
      ctrl_student_HIL_P.RandomNumber_StdDev_c +
      ctrl_student_HIL_P.RandomNumber_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S27>/Random Number' */

    /* InitializeConditions for MATLAB Function: '<S27>/Freeze signal' */
    ctrl_student__Freezesignal_Init(&ctrl_student_HIL_DW.sf_Freezesignal_g);/* InitializeConditions for Integrator: '<S2>/Integrator' */

    {
      int_T i1;
      real_T *xc = &ctrl_student_HIL_X.Integrator_CSTATE[0];
      for (i1=0; i1 < 9; i1++) {
        xc[i1] = (ctrl_student_HIL_P.Par.Observer.x_0[i1]);
      }
    }

    /* InitializeConditions for Integrator: '<S11>/Integrator1' */
    ctrl_student_HIL_X.Integrator1_CSTATE = (ctrl_student_HIL_P.Par.Guidance.s_0);

    /* InitializeConditions for MATLAB Function: '<S11>/eta_d_ellipsoid' */
    ctrl_student_HIL_DW.psi_old_not_empty = false;

    /* InitializeConditions for Derivative: '<S10>/Derivative' */
    ctrl_student_HIL_DW.TimeStampA = (rtInf);
    ctrl_student_HIL_DW.TimeStampB = (rtInf);

    /* InitializeConditions for MATLAB Function: '<S4>/Detect droput' */
    ctrl_student_HIL_DW.eta_old_not_empty = false;

    /* InitializeConditions for Integrator: '<S40>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator_CSTATE_n = 0.0;
    }

    ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S41>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator_CSTATE_l = 0.0;
    }

    ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S42>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator_CSTATE_m = 0.0;
    }

    ctrl_student_HIL_DW.Integrator_IWORK_o.IcNeedsLoading = 1;

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
      char fileName[509] = "log.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error closing MAT-file log.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error reopening MAT-file log.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 28, ctrl_student_HIL_DW.ToFile_IWORK.Count,
           "x")) {
        rtmSetErrorStatus(ctrl_student_HIL_M,
                          "Error writing header for x to MAT-file log.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_student_HIL_M, "Error closing MAT-file log.mat");
        return;
      }

      ctrl_student_HIL_DW.ToFile_PWORK.FilePtr = (NULL);
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
  ctrl_student_HIL_M->Sizes.numContStates = (13);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (168);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (71);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (442);/* Sum of parameter "widths" */
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

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 38:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 40:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 43:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 44:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 45:
    return NIRT_GetValueByDataType(ptr,subindex,10,Complex);

   case 48:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 49:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 60:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);

   case 61:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 62:
    return NIRT_GetValueByDataType(ptr,subindex,15,Complex);

   case 63:
    return NIRT_GetValueByDataType(ptr,subindex,16,Complex);

   case 64:
    return NIRT_GetValueByDataType(ptr,subindex,17,Complex);

   case 65:
    return NIRT_GetValueByDataType(ptr,subindex,20,Complex);

   case 66:
    return NIRT_GetValueByDataType(ptr,subindex,22,Complex);

   case 67:
    return NIRT_GetValueByDataType(ptr,subindex,24,Complex);

   case 68:
    return NIRT_GetValueByDataType(ptr,subindex,35,Complex);

   case 69:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 70:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);

   case 71:
    return NIRT_GetValueByDataType(ptr,subindex,35,Complex);

   case 72:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);

   case 73:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);

   case 74:
    return NIRT_GetValueByDataType(ptr,subindex,35,Complex);
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

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 36:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 37:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 40:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 43:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 44:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 45:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,10,Complex);

   case 48:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 49:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 60:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);

   case 61:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 62:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,15,Complex);

   case 63:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,16,Complex);

   case 64:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,17,Complex);

   case 65:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,20,Complex);

   case 66:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,22,Complex);

   case 67:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,24,Complex);

   case 68:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,35,Complex);

   case 69:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 70:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);

   case 71:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,35,Complex);

   case 72:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);

   case 73:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);

   case 74:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,35,Complex);
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

  // Noise and dropout/Enable_noise
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Enable_noise, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Noise and dropout/Dropout generation/Enable_dropout
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Enable_dropout, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Guidance and control/Control/K_p
  if (TaskSampleHit[0]) {
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_B.K_p, count, data[index++], 18,
        0);
    }
  } else {
    index += 9;
  }

  // Model_reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Model_reset, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Guidance and control/Guidance/ellipsoid_r
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_r, 0, data[index++],
      14, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_r, 1, data[index++],
      14, 0);
  } else {
    index += 2;
  }

  // Guidance and control/Guidance/ellipsoid_c
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_c, 0, data[index++],
      14, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_c, 1, data[index++],
      14, 0);
  } else {
    index += 2;
  }

  // Guidance and control/Guidance/ellipsoid_constant_heading_on_off
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_constant_heading_on_o,
      0, data[index++], 61, 0);
  } else {
    index += 1;
  }

  // Guidance and control/Guidance/ellipsoid_heading
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_heading, 0, data[index
      ++], 61, 0);
  } else {
    index += 1;
  }

  // Guidance and control/Guidance/ellipsoid_eta_0
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_eta_0, 0, data[index++],
      25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_eta_0, 1, data[index++],
      25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_eta_0, 2, data[index++],
      25, 0);
  } else {
    index += 3;
  }

  // Guidance and control/Guidance/switch_straight_ellipsoid
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.switch_straight_ellipsoid, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Guidance and control/Guidance/straight_eta_d_0
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.straight_eta_d_0, 0, data[index
      ++], 14, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.straight_eta_d_0, 1, data[index
      ++], 14, 0);
  } else {
    index += 2;
  }

  // Guidance and control/Guidance/mu
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.mu, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Guidance and control/Guidance/u_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Guidance and control/Control/C_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.C_2, 0, data[index++], 61, 0);
  } else {
    index += 1;
  }

  // Guidance and control/Guidance/straight_eta_d_1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.straight_eta_d_1, 0, data[index
      ++], 14, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.straight_eta_d_1, 1, data[index
      ++], 14, 0);
  } else {
    index += 2;
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

  // Enable_controller
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Enable_controller, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Luenberger Observer/L_1
  if (TaskSampleHit[1]) {
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_B.L_1, count, data[index++], 18,
        0);
    }
  } else {
    index += 9;
  }

  // Luenberger Observer/L_2
  if (TaskSampleHit[0]) {
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_B.L_2, count, data[index++], 18,
        0);
    }
  } else {
    index += 9;
  }

  // Luenberger Observer/L_3
  if (TaskSampleHit[1]) {
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_B.L_3, count, data[index++], 18,
        0);
    }
  } else {
    index += 9;
  }

  // Noise and dropout/Noise_power
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Noise_power, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 76;
}

double ni_extout[48];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // eta_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,0,
      32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,1,
      32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,2,
      32,0);
  } else {
    index += 3;
  }

  // Guidance and control/Control/alpha: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,0,25,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,1,25,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,2,25,
      0);
  } else {
    index += 3;
  }

  // Guidance and control/Guidance/s: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      0,0,0);
  } else {
    index += 1;
  }

  // tau_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,
      0,32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,
      1,32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,
      2,32,0);
  } else {
    index += 3;
  }

  // eta: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta,0,32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta,1,32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta,2,32,0);
  } else {
    index += 3;
  }

  // nu: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.nu,0,32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.nu,1,32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.nu,2,32,0);
  } else {
    index += 3;
  }

  // x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    for (count = 0; count < 9; count++) {
      ni_extout[index++] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_B.Integrator,count,30,0);
    }
  } else {
    index += 9;
  }

  // tau_control: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,0,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,1,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,2,25,0);
  } else {
    index += 3;
  }

  // eta_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,0,
      30,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,1,
      30,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,2,
      30,0);
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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,
      0,32,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,
      2,32,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,
      1,32,0);
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
      (&ctrl_student_HIL_P.Constant1_Value_h,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Model_reset,
      0,0,0);
  } else {
    index += 1;
  }

  // Luenberger Observer/eta_m_observer: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,0,
      32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,1,
      32,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,2,
      32,0);
  } else {
    index += 3;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 48;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // eta_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,0,32,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,1,32,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,2,32,
    0);

  // Guidance and control/Control/alpha: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,2,25,0);

  // Guidance and control/Guidance/s: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,0,
    0,0);

  // tau_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,0,
    32,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,1,
    32,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,2,
    32,0);

  // eta: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta,0,32,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta,1,32,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta,2,32,0);

  // nu: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.nu,0,32,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.nu,1,32,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.nu,2,32,0);

  // x_hat: Virtual Signal # 0
  for (count = 0; count < 9; count++) {
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      count,30,0);
  }

  // tau_control: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,2,25,0);

  // eta_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,0,30,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,1,30,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_j,2,30,
    0);

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
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,0,
    32,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,2,
    32,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Saturation,1,
    32,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value_h,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Model_reset,0,
    0,0);

  // Luenberger Observer/eta_m_observer: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,0,32,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,1,32,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch_m,2,32,
    0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil/Gain1/Gain", offsetof(P_ctrl_student_HIL_T, Par), 60, 1,
    2, 0, 0 },

  { 1, "ctrl_student_hil/Luenberger Observer/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/Luenberger Observer/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Par), 60, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/Noise and dropout/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/Workspace saturation1/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/Workspace saturation1/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/Workspace saturation1/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/Workspace saturation1/Constant3/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/Workspace saturation1/Constant4/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/Workspace saturation1/Constant5/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil/Guidance and control/Control/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 60, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil/Guidance and control/Guidance/Integrator1/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Par), 60, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal /Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 60, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal /Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 60, 1, 2, 26, 0 },

  { 14,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 1/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 60, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 1/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 60, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 2/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 60, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 2/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Par), 60, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/Gain/Gain", offsetof(P_ctrl_student_HIL_T, Gain_Gain),
    61, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil/Noise and dropout/Noise generator/Step size/Value",
    offsetof(P_ctrl_student_HIL_T, Stepsize_Value), 61, 1, 2, 38, 0 },

  { 20,
    "ctrl_student_hil/Noise and dropout/Noise generator/Downsamplesignal/counter/X0",
    offsetof(P_ctrl_student_HIL_T, counter_X0), 61, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/Noise and dropout/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, Constant1_Value), 61, 1, 2, 42, 0 },

  { 22,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean), 61, 1, 2, 44, 0 },

  { 23,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev), 61, 1, 2, 46, 0 },

  { 24,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed), 61, 1, 2, 48, 0 },

  { 25,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_p), 61, 1, 2, 50, 0 },

  { 26,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_k), 61, 1, 2, 52, 0 },

  { 27,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_m), 61, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil/Noise and dropout/Gain/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain_Gain_i), 61, 1, 2, 56, 0 },

  { 29,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_k), 61, 1, 2, 58, 0 },

  { 30,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_i), 61, 1, 2, 60, 0 },

  { 31,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_h), 61, 1, 2, 62, 0 },

  { 32,
    "ctrl_student_hil/Noise and dropout/Noise generator/Sample & hold/Hold/X0",
    offsetof(P_ctrl_student_HIL_T, Hold_X0), 61, 1, 2, 64, 0 },

  { 33,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal /Random Number/Mean",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Mean), 61, 1, 2, 66, 0 },

  { 34,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal /Random Number/StdDev",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_StdDev), 61, 1, 2, 68, 0 },

  { 35,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal /Random Number/Seed",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Seed), 61, 1, 2, 70, 0 },

  { 36,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 1/Random Number/Mean",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Mean_p), 61, 1, 2, 72, 0 },

  { 37,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 1/Random Number/StdDev",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_StdDev_d), 61, 1, 2, 74, 0 },

  { 38,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 1/Random Number/Seed",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Seed_c), 61, 1, 2, 76, 0 },

  { 39,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 2/Random Number/Mean",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Mean_h), 61, 1, 2, 78, 0 },

  { 40,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 2/Random Number/StdDev",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_StdDev_c), 61, 1, 2, 80, 0 },

  { 41,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 2/Random Number/Seed",
    offsetof(P_ctrl_student_HIL_T, RandomNumber_Seed_o), 61, 1, 2, 82, 0 },

  { 42, "ctrl_student_hil/Noise and dropout/Dropout generation/Switch/Threshold",
    offsetof(P_ctrl_student_HIL_T, Switch_Threshold), 61, 1, 2, 84, 0 },

  { 43, "ctrl_student_hil/Guidance and control/Guidance/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value), 23, 2, 2, 86, 0 },

  { 44, "ctrl_student_hil/Workspace saturation1/Saturation/UpperLimit", offsetof
    (P_ctrl_student_HIL_T, Saturation_UpperSat), 21, 3, 2, 88, 0 },

  { 45, "ctrl_student_hil/Workspace saturation1/Saturation/LowerLimit", offsetof
    (P_ctrl_student_HIL_T, Saturation_LowerSat), 21, 3, 2, 90, 0 },

  { 46, "ctrl_student_hil/Thrust Allocation/Inverse of T/Value", offsetof
    (P_ctrl_student_HIL_T, InverseofT_Value), 18, 9, 2, 92, 0 },

  { 47, "ctrl_student_hil/Sixaxis2force/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_n), 61, 1, 2, 94, 0 },

  { 48,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 61, 1, 2, 96, 0 },

  { 49,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_i), 61, 1, 2, 98, 0 },

  { 50,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_h), 61, 1, 2, 100, 0 },

  { 51, "ctrl_student_hil/Luenberger Observer/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_m), 18, 9, 2, 102, 0 },

  { 52, "ctrl_student_hil/Luenberger Observer/Constant3/Value", offsetof
    (P_ctrl_student_HIL_T, Constant3_Value), 18, 9, 2, 104, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 53;
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
  1, 1,                                /* Parameter at index 13 */
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
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 2,                                /* Parameter at index 43 */
  1, 3,                                /* Parameter at index 44 */
  1, 3,                                /* Parameter at index 45 */
  3, 3,                                /* Parameter at index 46 */
  1, 1,                                /* Parameter at index 47 */
  1, 1,                                /* Parameter at index 48 */
  1, 1,                                /* Parameter at index 49 */
  1, 1,                                /* Parameter at index 50 */
  3, 3,                                /* Parameter at index 51 */
  3, 3,                                /* Parameter at index 52 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise x/Product",
    0, "", offsetof(B_ctrl_student_HIL_T, Product)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 1,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise y/Product",
    0, "", offsetof(B_ctrl_student_HIL_T, Product_l)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2,
    "ctrl_student_hil/Noise and dropout/Noise generator/noise generator/Band-limited white noise psi/Product",
    0, "", offsetof(B_ctrl_student_HIL_T, Product_c)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/y_in", 0, "", offsetof(B_ctrl_student_HIL_T, y_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/x_in", 0, "", offsetof(B_ctrl_student_HIL_T, x_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/psi_in", 0, "", offsetof(B_ctrl_student_HIL_T, psi_in)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/Noise and dropout/Noise generator/Sample & hold/Hold",
    0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Hold)+0*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/Noise and dropout/Noise generator/Sample & hold/Hold",
    0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Hold)+1*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/Noise and dropout/Noise generator/Sample & hold/Hold",
    0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Hold)+2*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/Noise and dropout/Enable_noise", 0, "", offsetof
    (B_ctrl_student_HIL_T, Enable_noise)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    18, 0 },

  { 10, "ctrl_student_hil/Noise and dropout/Noise generator/Switch", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Switch)+0*sizeof(real_T), BLOCKIO_SIG, 32, 1,
    2, 20, 0 },

  { 11, "ctrl_student_hil/Noise and dropout/Noise generator/Switch", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Switch)+1*sizeof(real_T), BLOCKIO_SIG, 32, 1,
    2, 22, 0 },

  { 12, "ctrl_student_hil/Noise and dropout/Noise generator/Switch", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Switch)+2*sizeof(real_T), BLOCKIO_SIG, 32, 1,
    2, 24, 0 },

  { 13,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal /Clock",
    0, "", offsetof(B_ctrl_student_HIL_T, Clock)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 26, 0 },

  { 14,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal /Random Number",
    0, "", offsetof(B_ctrl_student_HIL_T, RandomNumber)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 1/Clock",
    0, "", offsetof(B_ctrl_student_HIL_T, Clock_f)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 1/Random Number",
    0, "", offsetof(B_ctrl_student_HIL_T, RandomNumber_c)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 2/Clock",
    0, "", offsetof(B_ctrl_student_HIL_T, Clock_b)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 34, 0 },

  { 18,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 2/Random Number",
    0, "", offsetof(B_ctrl_student_HIL_T, RandomNumber_l)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil/Noise and dropout/Dropout generation/Enable_dropout",
    0, "", offsetof(B_ctrl_student_HIL_T, Enable_dropout)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 38, 0 },

  { 20, "ctrl_student_hil/Noise and dropout/Dropout generation/Switch", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, Switch_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/Noise and dropout/Dropout generation/Switch", 0,
    "(1,2)", offsetof(B_ctrl_student_HIL_T, Switch_m)+1*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil/Noise and dropout/Dropout generation/Switch", 0,
    "(1,3)", offsetof(B_ctrl_student_HIL_T, Switch_m)+2*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, K_p)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    46, 0 },

  { 24, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(2,1)",
    offsetof(B_ctrl_student_HIL_T, K_p)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    48, 0 },

  { 25, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(3,1)",
    offsetof(B_ctrl_student_HIL_T, K_p)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    50, 0 },

  { 26, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, K_p)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    52, 0 },

  { 27, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(2,2)",
    offsetof(B_ctrl_student_HIL_T, K_p)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    54, 0 },

  { 28, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(3,2)",
    offsetof(B_ctrl_student_HIL_T, K_p)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    56, 0 },

  { 29, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, K_p)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    58, 0 },

  { 30, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(2,3)",
    offsetof(B_ctrl_student_HIL_T, K_p)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    60, 0 },

  { 31, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(3,3)",
    offsetof(B_ctrl_student_HIL_T, K_p)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    62, 0 },

  { 32, "ctrl_student_hil/Model_reset", 0, "", offsetof(B_ctrl_student_HIL_T,
    Model_reset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 64, 0 },

  { 33, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    66, 0 },

  { 34, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    68, 0 },

  { 35, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    70, 0 },

  { 36, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+3*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    72, 0 },

  { 37, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+4*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    74, 0 },

  { 38, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+5*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    76, 0 },

  { 39, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+6*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    78, 0 },

  { 40, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+7*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    80, 0 },

  { 41, "ctrl_student_hil/Luenberger Observer/Integrator", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+8*sizeof(real_T), BLOCKIO_SIG, 30, 1, 2,
    82, 0 },

  { 42, "ctrl_student_hil/Guidance and control/Guidance/Integrator1", 0, "",
    offsetof(B_ctrl_student_HIL_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 84, 0 },

  { 43, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_r", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, ellipsoid_r)+0*sizeof(real_T), BLOCKIO_SIG,
    14, 1, 2, 86, 0 },

  { 44, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_r", 0, "(2,1)",
    offsetof(B_ctrl_student_HIL_T, ellipsoid_r)+1*sizeof(real_T), BLOCKIO_SIG,
    14, 1, 2, 88, 0 },

  { 45, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_c", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, ellipsoid_c)+0*sizeof(real_T), BLOCKIO_SIG,
    14, 1, 2, 90, 0 },

  { 46, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_c", 0, "(2,1)",
    offsetof(B_ctrl_student_HIL_T, ellipsoid_c)+1*sizeof(real_T), BLOCKIO_SIG,
    14, 1, 2, 92, 0 },

  { 47,
    "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_constant_heading_on_off",
    0, "", offsetof(B_ctrl_student_HIL_T, ellipsoid_constant_heading_on_o)+0*
    sizeof(real_T), BLOCKIO_SIG, 61, 1, 2, 94, 0 },

  { 48, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_heading", 0,
    "", offsetof(B_ctrl_student_HIL_T, ellipsoid_heading)+0*sizeof(real_T),
    BLOCKIO_SIG, 61, 1, 2, 96, 0 },

  { 49, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_eta_0", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, ellipsoid_eta_0)+0*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 98, 0 },

  { 50, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_eta_0", 0,
    "(2,1)", offsetof(B_ctrl_student_HIL_T, ellipsoid_eta_0)+1*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 100, 0 },

  { 51, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_eta_0", 0,
    "(3,1)", offsetof(B_ctrl_student_HIL_T, ellipsoid_eta_0)+2*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 102, 0 },

  { 52,
    "ctrl_student_hil/Guidance and control/Guidance/switch_straight_ellipsoid",
    0, "", offsetof(B_ctrl_student_HIL_T, switch_straight_ellipsoid)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 104, 0 },

  { 53, "ctrl_student_hil/Guidance and control/Guidance/straight_eta_d_0", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, straight_eta_d_0)+0*sizeof(real_T),
    BLOCKIO_SIG, 14, 1, 2, 106, 0 },

  { 54, "ctrl_student_hil/Guidance and control/Guidance/straight_eta_d_0", 0,
    "(2,1)", offsetof(B_ctrl_student_HIL_T, straight_eta_d_0)+1*sizeof(real_T),
    BLOCKIO_SIG, 14, 1, 2, 108, 0 },

  { 55, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+0*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 110, 0 },

  { 56, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+1*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 112, 0 },

  { 57, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+2*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 114, 0 },

  { 58, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,4)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+3*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 116, 0 },

  { 59, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,5)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+4*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 118, 0 },

  { 60, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,6)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+5*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 120, 0 },

  { 61, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,7)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+6*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 122, 0 },

  { 62, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,8)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+7*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 124, 0 },

  { 63, "ctrl_student_hil/Guidance and control/Guidance/Switch", 0, "(1,9)",
    offsetof(B_ctrl_student_HIL_T, Switch_j)+8*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 126, 0 },

  { 64, "ctrl_student_hil/Guidance and control/Guidance/mu", 0, "", offsetof
    (B_ctrl_student_HIL_T, mu)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 128, 0 },

  { 65, "ctrl_student_hil/Guidance and control/Guidance/u_ref", 0, "", offsetof
    (B_ctrl_student_HIL_T, u_ref)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 130, 0
  },

  { 66, "ctrl_student_hil/Guidance and control/Control/C_2", 0, "", offsetof
    (B_ctrl_student_HIL_T, C_2)+0*sizeof(real_T), BLOCKIO_SIG, 61, 1, 2, 132, 0
  },

  { 67, "ctrl_student_hil/Guidance and control/Guidance/straight_eta_d_1", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, straight_eta_d_1)+0*sizeof(real_T),
    BLOCKIO_SIG, 14, 1, 2, 134, 0 },

  { 68, "ctrl_student_hil/Guidance and control/Guidance/straight_eta_d_1", 0,
    "(2,1)", offsetof(B_ctrl_student_HIL_T, straight_eta_d_1)+1*sizeof(real_T),
    BLOCKIO_SIG, 14, 1, 2, 136, 0 },

  { 69, "ctrl_student_hil/Guidance and control/Control/Derivative", 0, "",
    offsetof(B_ctrl_student_HIL_T, Derivative)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 138, 0 },

  { 70, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    140, 0 },

  { 71, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    142, 0 },

  { 72, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    144, 0 },

  { 73, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    146, 0 },

  { 74, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 148,
    0 },

  { 75, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 150,
    0 },

  { 76, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 152, 0 },

  { 77, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 154, 0 },

  { 78, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    156, 0 },

  { 79, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 158,
    0 },

  { 80, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    160, 0 },

  { 81, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    162, 0 },

  { 82, "ctrl_student_hil/Enable_controller", 0, "", offsetof
    (B_ctrl_student_HIL_T, Enable_controller)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 164, 0 },

  { 83, "ctrl_student_hil/Workspace saturation1/Saturation", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Saturation)+0*sizeof(real_T), BLOCKIO_SIG, 32,
    1, 2, 166, 0 },

  { 84, "ctrl_student_hil/Workspace saturation1/Saturation", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Saturation)+1*sizeof(real_T), BLOCKIO_SIG, 32,
    1, 2, 168, 0 },

  { 85, "ctrl_student_hil/Workspace saturation1/Saturation", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Saturation)+2*sizeof(real_T), BLOCKIO_SIG, 32,
    1, 2, 170, 0 },

  { 86, "ctrl_student_hil/r_in", 0, "", offsetof(B_ctrl_student_HIL_T, r_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 172, 0 },

  { 87, "ctrl_student_hil/u_in", 0, "", offsetof(B_ctrl_student_HIL_T, u_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 174, 0 },

  { 88, "ctrl_student_hil/v_in", 0, "", offsetof(B_ctrl_student_HIL_T, v_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 176, 0 },

  { 89, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L_1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 178, 0
  },

  { 90, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L_1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 180, 0
  },

  { 91, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L_1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 182, 0
  },

  { 92, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, L_1)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 184, 0
  },

  { 93, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(2,2)", offsetof
    (B_ctrl_student_HIL_T, L_1)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 186, 0
  },

  { 94, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(3,2)", offsetof
    (B_ctrl_student_HIL_T, L_1)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 188, 0
  },

  { 95, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, L_1)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 190, 0
  },

  { 96, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(2,3)", offsetof
    (B_ctrl_student_HIL_T, L_1)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 192, 0
  },

  { 97, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(3,3)", offsetof
    (B_ctrl_student_HIL_T, L_1)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 194, 0
  },

  { 98, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L_2)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 196, 0
  },

  { 99, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L_2)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 198, 0
  },

  { 100, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L_2)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 200, 0
  },

  { 101, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, L_2)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 202, 0
  },

  { 102, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(2,2)", offsetof
    (B_ctrl_student_HIL_T, L_2)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 204, 0
  },

  { 103, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(3,2)", offsetof
    (B_ctrl_student_HIL_T, L_2)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 206, 0
  },

  { 104, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, L_2)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 208, 0
  },

  { 105, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(2,3)", offsetof
    (B_ctrl_student_HIL_T, L_2)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 210, 0
  },

  { 106, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(3,3)", offsetof
    (B_ctrl_student_HIL_T, L_2)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 212, 0
  },

  { 107, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L_3)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 214, 0
  },

  { 108, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L_3)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 216, 0
  },

  { 109, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L_3)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 218, 0
  },

  { 110, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, L_3)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 220, 0
  },

  { 111, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(2,2)", offsetof
    (B_ctrl_student_HIL_T, L_3)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 222, 0
  },

  { 112, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(3,2)", offsetof
    (B_ctrl_student_HIL_T, L_3)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 224, 0
  },

  { 113, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, L_3)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 226, 0
  },

  { 114, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(2,3)", offsetof
    (B_ctrl_student_HIL_T, L_3)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 228, 0
  },

  { 115, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(3,3)", offsetof
    (B_ctrl_student_HIL_T, L_3)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 230, 0
  },

  { 116, "ctrl_student_hil/Noise and dropout/Noise_power", 0, "", offsetof
    (B_ctrl_student_HIL_T, Noise_power)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    232, 0 },

  { 117, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 0, "u_VSP", offsetof
    (B_ctrl_student_HIL_T, u_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 234, 0
  },

  { 118, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 1, "alpha_VSP",
    offsetof(B_ctrl_student_HIL_T, alpha_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 236, 0 },

  { 119, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 2, "u_BT", offsetof
    (B_ctrl_student_HIL_T, u_BT)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 238, 0
  },

  { 120,
    "ctrl_student_hil/Noise and dropout/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,1)", offsetof(B_ctrl_student_HIL_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 240, 0 },

  { 121,
    "ctrl_student_hil/Noise and dropout/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,2)", offsetof(B_ctrl_student_HIL_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 242, 0 },

  { 122,
    "ctrl_student_hil/Noise and dropout/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,3)", offsetof(B_ctrl_student_HIL_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 32, 1, 2, 244, 0 },

  { 123,
    "ctrl_student_hil/Noise and dropout/Noise generator/Downsamplesignal/MATLAB Function",
    0, "count", offsetof(B_ctrl_student_HIL_T, count)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 246, 0 },

  { 124, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,1)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+0*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 248, 0 },

  { 125, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,2)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+1*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 250, 0 },

  { 126, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,3)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+2*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 252, 0 },

  { 127, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,4)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+3*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 254, 0 },

  { 128, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,5)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+4*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 256, 0 },

  { 129, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,6)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+5*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 258, 0 },

  { 130, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,7)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+6*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 260, 0 },

  { 131, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,8)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+7*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 262, 0 },

  { 132, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,9)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+8*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 264, 0 },

  { 133, "ctrl_student_hil/Guidance and control/Guidance/update law", 0, "s_dot",
    offsetof(B_ctrl_student_HIL_T, s_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    266, 0 },

  { 134, "ctrl_student_hil/Guidance and control/Guidance/update law", 1, "U_s",
    offsetof(B_ctrl_student_HIL_T, U_s)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    268, 0 },

  { 135, "ctrl_student_hil/Guidance and control/Control/tau", 0, "tau(1,1)",
    offsetof(B_ctrl_student_HIL_T, tau)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    270, 0 },

  { 136, "ctrl_student_hil/Guidance and control/Control/tau", 0, "tau(2,1)",
    offsetof(B_ctrl_student_HIL_T, tau)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    272, 0 },

  { 137, "ctrl_student_hil/Guidance and control/Control/tau", 0, "tau(3,1)",
    offsetof(B_ctrl_student_HIL_T, tau)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    274, 0 },

  { 138, "ctrl_student_hil/Guidance and control/Control/alfa1", 0, "alfa1(1,1)",
    offsetof(B_ctrl_student_HIL_T, alfa1)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1,
    2, 276, 0 },

  { 139, "ctrl_student_hil/Guidance and control/Control/alfa1", 0, "alfa1(2,1)",
    offsetof(B_ctrl_student_HIL_T, alfa1)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1,
    2, 278, 0 },

  { 140, "ctrl_student_hil/Guidance and control/Control/alfa1", 0, "alfa1(3,1)",
    offsetof(B_ctrl_student_HIL_T, alfa1)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1,
    2, 280, 0 },

  { 141, "ctrl_student_hil/Signal Dropout detection/Detect droput", 1,
    "dropout(1,1)", offsetof(B_ctrl_student_HIL_T, dropout)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 44, 1, 2, 282, 0 },

  { 142, "ctrl_student_hil/Signal Dropout detection/Detect droput", 1,
    "dropout(1,2)", offsetof(B_ctrl_student_HIL_T, dropout)+1*sizeof(boolean_T),
    BLOCKIO_SIG, 44, 1, 2, 284, 0 },

  { 143, "ctrl_student_hil/Signal Dropout detection/Detect droput", 1,
    "dropout(1,3)", offsetof(B_ctrl_student_HIL_T, dropout)+2*sizeof(boolean_T),
    BLOCKIO_SIG, 44, 1, 2, 286, 0 },

  { 144,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 2/Freeze signal",
    0, "eta_out", offsetof(B_ctrl_student_HIL_T, sf_Freezesignal_g.eta_out)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 288, 0 },

  { 145,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal 1/Freeze signal",
    0, "eta_out", offsetof(B_ctrl_student_HIL_T, sf_Freezesignal_k.eta_out)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 290, 0 },

  { 146,
    "ctrl_student_hil/Noise and dropout/Dropout generation/Freeze Signal /Freeze signal",
    0, "eta_out", offsetof(B_ctrl_student_HIL_T, sf_Freezesignal.eta_out)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 292, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 147;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 62;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 1, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "Noise and dropout/Enable_noise", 0, EXT_IN, 1, 1, 1 },

  { 4, "Noise and dropout/Dropout generation/Enable_dropout", 0, EXT_IN, 1, 1, 1
  },

  { 5, "Guidance and control/Control/K_p", 0, EXT_IN, 9, 3, 3 },

  { 6, "Model_reset", 0, EXT_IN, 1, 1, 1 },

  { 7, "Guidance and control/Guidance/ellipsoid_r", 0, EXT_IN, 2, 2, 1 },

  { 8, "Guidance and control/Guidance/ellipsoid_c", 0, EXT_IN, 2, 2, 1 },

  { 9, "Guidance and control/Guidance/ellipsoid_constant_heading_on_off", 0,
    EXT_IN, 1, 1, 1 },

  { 10, "Guidance and control/Guidance/ellipsoid_heading", 0, EXT_IN, 1, 1, 1 },

  { 11, "Guidance and control/Guidance/ellipsoid_eta_0", 0, EXT_IN, 3, 3, 1 },

  { 12, "Guidance and control/Guidance/switch_straight_ellipsoid", 0, EXT_IN, 1,
    1, 1 },

  { 13, "Guidance and control/Guidance/straight_eta_d_0", 0, EXT_IN, 2, 2, 1 },

  { 14, "Guidance and control/Guidance/mu", 0, EXT_IN, 1, 1, 1 },

  { 15, "Guidance and control/Guidance/u_ref", 0, EXT_IN, 1, 1, 1 },

  { 16, "Guidance and control/Control/C_2", 0, EXT_IN, 1, 1, 1 },

  { 17, "Guidance and control/Guidance/straight_eta_d_1", 1, EXT_IN, 2, 2, 1 },

  { 18, "joystick/L2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 19, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 20, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 21, "joystick/R2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 22, "joystick/PosXLeft", 0, EXT_IN, 1, 1, 1 },

  { 23, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 24, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 25, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 26, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 27, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 28, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 29, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 30, "Enable_controller", 0, EXT_IN, 1, 1, 1 },

  { 31, "r_in", 0, EXT_IN, 1, 1, 1 },

  { 32, "u_in", 0, EXT_IN, 1, 1, 1 },

  { 33, "v_in", 0, EXT_IN, 1, 1, 1 },

  { 34, "Luenberger Observer/L_1", 1, EXT_IN, 9, 3, 3 },

  { 35, "Luenberger Observer/L_2", 0, EXT_IN, 9, 3, 3 },

  { 36, "Luenberger Observer/L_3", 1, EXT_IN, 9, 3, 3 },

  { 37, "Noise and dropout/Noise_power", 1, EXT_IN, 1, 1, 1 },

  { 0, "eta_m", 0, EXT_OUT, 3, 3, 1 },

  { 1, "Guidance and control/Control/alpha", 0, EXT_OUT, 3, 3, 1 },

  { 2, "Guidance and control/Guidance/s", 0, EXT_OUT, 1, 1, 1 },

  { 3, "tau_out", 0, EXT_OUT, 3, 3, 1 },

  { 4, "eta", 0, EXT_OUT, 3, 3, 1 },

  { 5, "nu", 0, EXT_OUT, 3, 3, 1 },

  { 6, "x_hat", 0, EXT_OUT, 9, 9, 1 },

  { 7, "tau_control", 0, EXT_OUT, 3, 3, 1 },

  { 8, "eta_d", 0, EXT_OUT, 3, 3, 1 },

  { 9, "Sixaxis2force/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Sixaxis2force/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Sixaxis2force/omega_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 12, "Sixaxis2force/omega_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 13, "Sixaxis2force/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Sixaxis2force/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 15, "Sixaxis2force/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 16, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 17, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 18, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 19, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 20, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 21, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 22, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

  { 23, "Luenberger Observer/eta_m_observer", 0, EXT_OUT, 3, 3, 1 },

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
static char* NI_CompiledModelVersion = "1.171";
static char* NI_CompiledModelDateTime = "Mon Apr 24 12:18:43 2017";
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
      *numContStates = 13;
      *numDiscStates = 3188;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    for (count = 0; count < 9; count++) {
      contStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_X.Integrator_CSTATE[0], count, 0, 0);
      strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    }

    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_n, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_l, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_m, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_m");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_m,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_m");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_n,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Enable_noise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Enable_noise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_o,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_os,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_os");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_e,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Enable_dropout_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Enable_dropout_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1,
      0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1,
      1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1,
      2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_m_DWORK1");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p_DWORK1,
        count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Model_reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Model_reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_r_DWORK1, 0, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_r_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_r_DWORK1, 1, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_r_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_c_DWORK1, 0, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_c_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_c_DWORK1, 1, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_c_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_constant_heading_on_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_constant_heading_on_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_heading_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_heading_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1, 0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1, 1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1, 2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.switch_straight_ellipsoid_DWORK, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.switch_straight_ellipsoid_DWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.straight_eta_d_0_DWORK1, 0, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.straight_eta_d_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.straight_eta_d_0_DWORK1, 1, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.straight_eta_d_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.mu_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.mu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_ref_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1,
      0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.alpha_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1,
      1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.alpha_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1,
      2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.alpha_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.C_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.C_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1, 0, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1, 1, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.TimeStampA, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.TimeStampA");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.LastUAtTimeA,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.LastUAtTimeA");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.TimeStampB, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.TimeStampB");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.LastUAtTimeB,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.LastUAtTimeB");
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
      (&ctrl_student_HIL_DW.Enable_controller_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Enable_controller_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_out_DWORK1, 0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_out_DWORK1, 1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_out_DWORK1, 2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_DWORK1, 0,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_DWORK1, 1,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_DWORK1, 2,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.nu_DWORK1, 0,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.nu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.nu_DWORK1, 1,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.nu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.nu_DWORK1, 2,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.nu_DWORK1");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_hat_DWORK1, count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_hat_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_control_DWORK1, 0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_control_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_control_DWORK1, 1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_control_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_control_DWORK1, 2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_control_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1,
      0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1,
      1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1,
      2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_d_DWORK1");
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
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L_1_DWORK1,
        count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L_1_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_m_observer_DWORK1, 0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_m_observer_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_m_observer_DWORK1, 1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_m_observer_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_m_observer_DWORK1, 2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_m_observer_DWORK1");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L_2_DWORK1,
        count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L_2_DWORK1");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L_3_DWORK1,
        count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L_3_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Noise_power_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Noise_power_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 0,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 1,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 2,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_old, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.ToFile_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.ToFile_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_l, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_k, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_e, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_n, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_m, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile_IWORK.Count, 0, 45, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ToFile_IWORK.Decimation, 0, 45, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ToFile_IWORK.Decimation");
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
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_in_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Enable_noise_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Enable_noise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Enable_dropout_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Enable_dropout_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_m_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_m_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Model_reset_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Model_reset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ellipsoid_r_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ellipsoid_r_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ellipsoid_c_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ellipsoid_c_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ellipsoid_constant_heading_on_a, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ellipsoid_constant_heading_on_a");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ellipsoid_heading_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ellipsoid_heading_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.switch_straight_ellipsoid_DWO_b, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.switch_straight_ellipsoid_DWO_b");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.straight_eta_d_0_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.straight_eta_d_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.mu_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.mu_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_ref_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_ref_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.C_2_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.C_2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.straight_eta_d_1_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.straight_eta_d_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_continuous_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXRight_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYRight_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.R2_continuous_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXLeft_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYLeft_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowDown_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowUp_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowRight_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Enable_controller_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Enable_controller_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_out_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.nu_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.nu_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_hat_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_control_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_control_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_d_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_0_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L_1_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_m_observer_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_m_observer_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L_2_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L_2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L_3_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L_3_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Noise_power_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Noise_power_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 41, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_old_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_old_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_old_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_old_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.eta, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_g.eta");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.t_1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_g.t_1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.method, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_g.method");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.state, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_g.state");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.state_j, 0, 42, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_g.state_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.state_j, 1, 42, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_g.state_j");
    for (count = 0; count < 625; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.sf_Freezesignal_g.state_p, count, 43, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.sf_Freezesignal_g.state_p");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.eta_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_g.eta_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.state_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_g.state_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.eta, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_k.eta");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.t_1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_k.t_1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.method, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_k.method");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.state, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_k.state");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.state_j, 0, 42, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_k.state_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.state_j, 1, 42, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_k.state_j");
    for (count = 0; count < 625; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.sf_Freezesignal_k.state_p, count, 43, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.sf_Freezesignal_k.state_p");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.eta_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_k.eta_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.state_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal_k.state_not_empty");
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
      (&ctrl_student_HIL_DW.sf_Freezesignal.state_j, 0, 42, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.state_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal.state_j, 1, 42, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.sf_Freezesignal.state_j");
    for (count = 0; count < 625; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.sf_Freezesignal.state_p, count, 43, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.sf_Freezesignal.state_p");
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
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE[0], count,
        contStates[idx++], 0, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_n, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_l, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_m, 0,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_m, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_n, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 2,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_noise_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_o, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_os, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_e, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_dropout_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1, 0, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1, 1, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK1, 2, discStates[idx
      ++], 32, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Model_reset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_r_DWORK1, 0,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_r_DWORK1, 1,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_c_DWORK1, 0,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_c_DWORK1, 1,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_constant_heading_on_o,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_heading_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK1, 2,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.switch_straight_ellipsoid_DWORK,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_0_DWORK1, 0,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_0_DWORK1, 1,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.mu_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_ref_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1, 0, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1, 1, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1, 2, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.C_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1, 0,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1, 1,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TimeStampA, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.LastUAtTimeA, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TimeStampB, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.LastUAtTimeB, 0, discStates[idx
      ++], 0, 0);
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_controller_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 2,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_DWORK1, 0, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_DWORK1, 1, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_DWORK1, 2, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_DWORK1, 0, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_DWORK1, 1, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_DWORK1, 2, discStates[idx++],
      32, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_control_DWORK1, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_control_DWORK1, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_control_DWORK1, 2,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1, 0, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1, 1, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1, 2, discStates[idx
      ++], 32, 0);
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
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_1_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_observer_DWORK1, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_observer_DWORK1, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_observer_DWORK1, 2,
      discStates[idx++], 32, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_2_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_3_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Noise_power_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 0, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 1, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 2, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_old, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_l, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_k, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_e, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_n, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_m, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_IWORK.Count, 0,
      discStates[idx++], 45, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ToFile_IWORK.Decimation, 0,
      discStates[idx++], 45, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading,
      0, discStates[idx++], 10, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK_m.IcNeedsLoading, 0, discStates[idx
       ++], 10, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK_o.IcNeedsLoading, 0, discStates[idx
       ++], 10, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_noise_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_dropout_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Model_reset_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_r_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_c_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_DW.ellipsoid_constant_heading_on_a, count,
         discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_heading_DWORK2,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ellipsoid_eta_0_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_DW.switch_straight_ellipsoid_DWO_b, count,
         discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_0_DWORK2,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.mu_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_ref_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.C_2_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_1_DWORK2,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_controller_DWORK2,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_control_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_1_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_m_observer_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_2_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_3_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Noise_power_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 41, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old_not_empty, 0,
      discStates[idx++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_old_not_empty, 0,
      discStates[idx++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_g.eta, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_g.t_1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_g.method, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_g.state, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_g.state_j, 0,
      discStates[idx++], 42, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_g.state_j, 1,
      discStates[idx++], 42, 0);
    for (count = 0; count < 625; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_g.state_p,
        count, discStates[idx++], 43, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_g.eta_not_empty,
      0, discStates[idx++], 8, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_g.state_not_empty, 0, discStates[idx
       ++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_k.eta, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_k.t_1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_k.method, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_k.state, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_k.state_j, 0,
      discStates[idx++], 42, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_k.state_j, 1,
      discStates[idx++], 42, 0);
    for (count = 0; count < 625; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_k.state_p,
        count, discStates[idx++], 43, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal_k.eta_not_empty,
      0, discStates[idx++], 8, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.sf_Freezesignal_k.state_not_empty, 0, discStates[idx
       ++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.eta, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.t_1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.method, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state_j, 0,
      discStates[idx++], 42, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state_j, 1,
      discStates[idx++], 42, 0);
    for (count = 0; count < 625; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.sf_Freezesignal.state_p,
        count, discStates[idx++], 43, 0);
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
