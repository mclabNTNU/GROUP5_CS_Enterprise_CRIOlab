/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_HIL_P            ctrl_student_HIL_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_HIL_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.170
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Apr 24 10:44:57 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_HIL_T ctrl_student_HIL_P = {
  {
    {
      { 0.0, 0.0 },
      2.2,
      250.0,
      100.0,
      -100.0,
      -100.0,
      100.0,
      -97.8,
      97.8,
      -97.8,
      97.8
    },

    {
      1.0,
      0.0001,
      100.0
    },

    {
      0.0,
      1.5,
      8.0,
      1.0
    },
    0.01,

    { 1.03, 2.5, 0.98 },

    {
      { 0.059559261465157838, 0.0, 0.0, 0.0, 0.063781377640431069,
        -0.012816359434559084, 0.0, -0.012816359434559084, 0.36489418584869804 },

      { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

      { 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 1.0 },

      { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

      { 11.0, 3.0, 1.5707963267948966, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    },

    {
      { 11.0, 3.0, 1.5707963267948966 }
    },

    {
      0.2,
      0.05,
      0.0,
      0.0,

      { 11.1, 3.1, 1.5707963267948966 },

      { 10.0, 10.0, 0.0 },

      { 0.1, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.5 },
      1.8,

      { 16.79, 0.0, 0.0, 0.0, 15.79, 0.5546, 0.0, 0.5546, 2.76 },
      1.0,

      { 6.0, 1.0 },

      { 5.0, 3.0 },
      0.0,
      1.5707963267948966
    }
  },                                   /* Variable: Par
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<S2>/Constant2'
                                        *   '<S2>/Integrator'
                                        *   '<S3>/Constant'
                                        *   '<S7>/Constant'
                                        *   '<S7>/Constant1'
                                        *   '<S7>/Constant2'
                                        *   '<S7>/Constant3'
                                        *   '<S7>/Constant4'
                                        *   '<S7>/Constant5'
                                        *   '<S10>/Constant'
                                        *   '<S11>/Integrator1'
                                        *   '<S25>/Constant'
                                        *   '<S25>/Constant1'
                                        *   '<S26>/Constant'
                                        *   '<S26>/Constant1'
                                        *   '<S27>/Constant'
                                        *   '<S27>/Constant1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S24>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Noise_power'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Noise_power'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Noise_power'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Noise_power'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Noise_power'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Noise_power'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S37>/White Noise'
                                        */
  267372.0,                            /* Expression: ceil(abs(7*round(abs(now*1e6 - fix(now*1e6))*1e5)))
                                        * Referenced by: '<S37>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_k
                                        * Referenced by: '<S38>/White Noise'
                                        */
  283521.0,                            /* Expression: ceil(abs(7*round(abs(now*1e6 - fix(now*1e6))*1e5)))
                                        * Referenced by: '<S38>/White Noise'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S3>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_i
                                        * Referenced by: '<S36>/White Noise'
                                        */
  259252.0,                            /* Expression: ceil(abs(7*round(abs(now*1e6 - fix(now*1e6))*1e5)))
                                        * Referenced by: '<S36>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Enable_noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Enable_noise'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Enable_noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Enable_noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Enable_noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Enable_noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S25>/Random Number'
                                        */
  1.0,                                 /* Computed Parameter: RandomNumber_StdDev
                                        * Referenced by: '<S25>/Random Number'
                                        */
  63660.0,                             /* Expression: ceil(abs(5*round(abs(now*1e6 - fix(now*1e6))*1e5)))
                                        * Referenced by: '<S25>/Random Number'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S26>/Random Number'
                                        */
  1.0,                                 /* Computed Parameter: RandomNumber_StdDev_d
                                        * Referenced by: '<S26>/Random Number'
                                        */
  92590.0,                             /* Expression: ceil(abs(5*round(abs(now*1e6 - fix(now*1e6))*1e5)))
                                        * Referenced by: '<S26>/Random Number'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/Random Number'
                                        */
  1.0,                                 /* Computed Parameter: RandomNumber_StdDev_c
                                        * Referenced by: '<S27>/Random Number'
                                        */
  121520.0,                            /* Expression: ceil(abs(5*round(abs(now*1e6 - fix(now*1e6))*1e5)))
                                        * Referenced by: '<S27>/Random Number'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/Enable_dropout'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/Enable_dropout'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/Enable_dropout'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/Enable_dropout'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/Enable_dropout'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/Enable_dropout'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_m'
                                        */

  /*  Expression: width
   * Referenced by: '<S10>/K_p'
   */
  { 3.0, 3.0 },
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/K_p'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/K_p'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/K_p'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/K_p'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/K_p'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S10>/C_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/C_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/C_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/C_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/C_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/C_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Model_reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Model_reset'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Model_reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Model_reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Model_reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Model_reset'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/mu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/mu'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/mu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/mu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/mu'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/mu'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/u_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/u_ref'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/u_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/u_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/u_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/u_ref'
                                        */
  2.0,                                 /* Expression: width
                                        * Referenced by: '<S11>/ellipsoid_r'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/ellipsoid_r'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/ellipsoid_r'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/ellipsoid_r'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/ellipsoid_r'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/ellipsoid_r'
                                        */
  2.0,                                 /* Expression: width
                                        * Referenced by: '<S11>/ellipsoid_c'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/ellipsoid_c'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/ellipsoid_c'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/ellipsoid_c'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/ellipsoid_c'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/ellipsoid_c'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S11>/ellipsoid_constant_heading_on_off'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/ellipsoid_constant_heading_on_off'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/ellipsoid_constant_heading_on_off'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/ellipsoid_constant_heading_on_off'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/ellipsoid_constant_heading_on_off'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/ellipsoid_constant_heading_on_off'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S11>/ellipsoid_heading'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/ellipsoid_heading'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/ellipsoid_heading'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/ellipsoid_heading'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/ellipsoid_heading'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/ellipsoid_heading'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S11>/ellipsoid_eta_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/ellipsoid_eta_0'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/ellipsoid_eta_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/ellipsoid_eta_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/ellipsoid_eta_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/ellipsoid_eta_0'
                                        */
  2.0,                                 /* Expression: width
                                        * Referenced by: '<S11>/straight_eta_d_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/straight_eta_d_0'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/straight_eta_d_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/straight_eta_d_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/straight_eta_d_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/straight_eta_d_0'
                                        */
  2.0,                                 /* Expression: width
                                        * Referenced by: '<S11>/straight_eta_d_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/straight_eta_d_1'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/straight_eta_d_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/straight_eta_d_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/straight_eta_d_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/straight_eta_d_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/switch_straight_ellipsoid'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/switch_straight_ellipsoid'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S11>/switch_straight_ellipsoid'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/switch_straight_ellipsoid'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/switch_straight_ellipsoid'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/switch_straight_ellipsoid'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Enable_controller'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Enable_controller'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Enable_controller'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Enable_controller'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Enable_controller'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Enable_controller'
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S7>/Saturation'
   */
  { 1.0, 1.0, 1.0 },

  /*  Expression: [-1 -1 -1]
   * Referenced by: '<S7>/Saturation'
   */
  { -1.0, -1.0, -1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_out'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/tau_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/nu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/nu'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/nu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/nu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/nu'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/nu'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_hat'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_control'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_control'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/tau_control'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_control'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_control'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_control'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_d'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_d'
                                        */

  /*  Expression: inv([1 0 0; 0 1 1; 0 -0.4575 0.3875])
   * Referenced by: '<S6>/Inverse of T'
   */
  { 1.0, 0.0, 0.0, -0.0, 0.45857988165680474, 0.54142011834319526, -0.0,
    -1.1834319526627219, 1.1834319526627219 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_VSP2'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S5>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/eta_m_observer'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/eta_m_observer'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/eta_m_observer'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/eta_m_observer'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/eta_m_observer'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/eta_m_observer'
                                        */

  /*  Expression: width
   * Referenced by: '<S2>/L_1'
   */
  { 3.0, 3.0 },
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L_1'
                                        */

  /*  Expression: width
   * Referenced by: '<S2>/L_2'
   */
  { 3.0, 3.0 },
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L_2'
                                        */

  /*  Expression: width
   * Referenced by: '<S2>/L_3'
   */
  { 3.0, 3.0 },
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L_3'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_student_HIL_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_student_HIL_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
