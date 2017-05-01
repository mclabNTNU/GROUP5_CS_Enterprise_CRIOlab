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
 * Model version              : 1.278
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon May 01 10:07:39 2017
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

    { 0.309, 0.75, 0.294 },

    {
      { 0.059559261465157838, 0.0, 0.0, 0.0, 0.063781377640431069,
        -0.012816359434559084, 0.0, -0.012816359434559084, 0.36489418584869804 },

      { 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 5.0 },

      { 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 10.0 },

      { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

      { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    },

    {
      { 0.0, 0.0, 0.0 }
    },

    {
      0.2,
      0.05,
      0.0,
      0.0,

      { 0.1, 0.1, 0.0 },

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
                                        *   '<S10>/Gain1'
                                        *   '<S11>/Saturation1'
                                        *   '<S28>/Constant1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain2'
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S7>/Saturation'
   */
  { 1.0, 1.0, 1.0 },

  /*  Expression: [-1 -1 -1]
   * Referenced by: '<S7>/Saturation'
   */
  { -1.0, -1.0, -1.0 },
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S3>/Constant'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S27>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S30>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Noise power '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Noise power '
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Noise power '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Noise power '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Noise power '
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Noise power '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S36>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S36>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_p
                                        * Referenced by: '<S37>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S37>/White Noise'
                                        */
  0.1,                                 /* Expression: 1/10
                                        * Referenced by: '<S3>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_h
                                        * Referenced by: '<S35>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S35>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/y_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/psi_in'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Enable noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Enable noise'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Enable noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Enable noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Enable noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Enable noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_in'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/v_in'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/v_in'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Random Number'
                                        */
  1.0,                                 /* Computed Parameter: RandomNumber_StdDev
                                        * Referenced by: '<S28>/Random Number'
                                        */
  75255.0,                             /* Expression: ceil(abs(5*round(abs(now*1e6 - fix(now*1e6))*1e5)))
                                        * Referenced by: '<S28>/Random Number'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/Freeze threshold'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/Freeze threshold'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/Freeze threshold'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/Freeze threshold'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/Freeze threshold'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/Freeze threshold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S26>/Enable dropout'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S26>/Enable dropout'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S26>/Enable dropout'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S26>/Enable dropout'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S26>/Enable dropout'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S26>/Enable dropout'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S26>/Switch'
                                        */

  /*  Expression: zeros(6,1)
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Model_reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Model_reset'
                                        */
  3.0,                                 /* Expression: portnum
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

  /*  Expression: width
   * Referenced by: '<S13>/K_p'
   */
  { 3.0, 3.0 },
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/K_p'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/K_p'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/K_p'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/K_p'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/K_p'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Integrator1'
                                        */
  2.0,                                 /* Expression: width
                                        * Referenced by: '<S14>/ellipsoid_r'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ellipsoid_r'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/ellipsoid_r'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ellipsoid_r'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ellipsoid_r'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ellipsoid_r'
                                        */
  2.0,                                 /* Expression: width
                                        * Referenced by: '<S14>/ellipsoid_c'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ellipsoid_c'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/ellipsoid_c'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ellipsoid_c'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ellipsoid_c'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ellipsoid_c'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S14>/ellipsoid_constant_heading_on_off'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ellipsoid_constant_heading_on_off'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/ellipsoid_constant_heading_on_off'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ellipsoid_constant_heading_on_off'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ellipsoid_constant_heading_on_off'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ellipsoid_constant_heading_on_off'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S14>/ellipsoid_heading'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ellipsoid_heading'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/ellipsoid_heading'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ellipsoid_heading'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ellipsoid_heading'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ellipsoid_heading'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S14>/ellipsoid_eta_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ellipsoid_eta_0'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/ellipsoid_eta_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ellipsoid_eta_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ellipsoid_eta_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ellipsoid_eta_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/switch_straight_ellipsoid'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/switch_straight_ellipsoid'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/switch_straight_ellipsoid'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/switch_straight_ellipsoid'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/switch_straight_ellipsoid'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/switch_straight_ellipsoid'
                                        */
  2.0,                                 /* Expression: width
                                        * Referenced by: '<S14>/straight_eta_d_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/straight_eta_d_0'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/straight_eta_d_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/straight_eta_d_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/straight_eta_d_0'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/straight_eta_d_0'
                                        */
  2.0,                                 /* Expression: width
                                        * Referenced by: '<S14>/straight_eta_d_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/straight_eta_d_1'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/straight_eta_d_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/straight_eta_d_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/straight_eta_d_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/straight_eta_d_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/stop_at_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/stop_at_pos'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/stop_at_pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/stop_at_pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/stop_at_pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/stop_at_pos'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/mu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/mu'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/mu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/mu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/mu'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/mu'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/u_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/u_ref'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/u_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/u_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/u_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/u_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<S13>/C_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/C_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/C_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/C_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/C_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/C_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/Z_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/Z_1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/Z_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/Z_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/Z_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/Z_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/Z_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/Z_2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/Z_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/Z_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/Z_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/Z_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/s'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/s'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/s'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/s'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/s'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/s'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/U_S'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/U_S'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/U_S'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/U_S'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/U_S'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/U_S'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/S_DOT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/S_DOT'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/S_DOT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/S_DOT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/S_DOT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/S_DOT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/enableController'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/enableController'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/enableController'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/enableController'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/enableController'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/enableController'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Enable_W_sat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Enable_W_sat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Enable_W_sat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Enable_W_sat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Enable_W_sat'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Enable_W_sat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/x_max'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/x_max'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/x_max'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/x_max'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/x_max'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/x_max'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/y_MAX'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/y_MAX'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/y_MAX'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/y_MAX'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/y_MAX'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/y_MAX'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/scale'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/scale'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/scale'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/scale'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/scale'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/scale'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/x_min'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/x_min'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/x_min'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/x_min'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/x_min'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/x_min'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_out'
                                        */
  1.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/alpha'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_control'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_control'
                                        */
  3.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_hat'
                                        */
  4.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/eta_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_d'
                                        */
  5.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_model'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_model'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/nu_model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/nu_model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/nu_model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/nu_model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/nu_model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/nu_model'
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
                                        * Referenced by: '<Root>/eta_meas'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_meas'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_meas'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_meas'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_meas'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_meas'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/integrator reset model'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/obs out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/obs out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/obs out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/obs out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/obs out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/obs out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Dropout_detected'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Dropout_detected'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Dropout_detected'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Dropout_detected'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Dropout_detected'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Dropout_detected'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 6, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
