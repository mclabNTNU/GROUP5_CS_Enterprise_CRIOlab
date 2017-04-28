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
 * Model version              : 1.271
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Apr 28 12:01:18 2017
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
                                        *   '<Root>/Gain1'
                                        *   '<S13>/Constant'
                                        *   '<S14>/Integrator1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain'
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S6>/Saturation'
   */
  { 1.0, 1.0, 1.0 },

  /*  Expression: [-1 -1 -1]
   * Referenced by: '<S6>/Saturation'
   */
  { -1.0, -1.0, -1.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/X_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/X_pos'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/X_pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/X_pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/X_pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/X_pos'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S9>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/Y_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/Y_pos'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/Y_pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/Y_pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/Y_pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/Y_pos'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S9>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/Psi_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/Psi_pos'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/Psi_pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/Psi_pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/Psi_pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/Psi_pos'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S9>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/meas_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/meas_out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/meas_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/meas_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/meas_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/meas_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/Residual'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/Residual'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/Residual'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/Residual'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/Residual'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/Residual'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S9>/Gain2'
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
                                        * Referenced by: '<S1>/Constant'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S14>/pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/pos'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/pos'
                                        */

  /*  Expression: zeros(6, 1)
   * Referenced by: '<S14>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/switch_keep_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/switch_keep_pos'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/switch_keep_pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/switch_keep_pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/switch_keep_pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/switch_keep_pos'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/stop_at_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/stop_at_pos'
                                        */
  13.0,                                /* Expression: portnum
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant2'
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
                                        * Referenced by: '<S6>/Enable_W_sat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Enable_W_sat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Enable_W_sat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Enable_W_sat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Enable_W_sat'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Enable_W_sat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/x_max'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/x_max'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/x_max'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/x_max'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/x_max'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/x_max'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/y_MAX'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/y_MAX'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/y_MAX'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/y_MAX'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/y_MAX'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/y_MAX'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/scale'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/scale'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/scale'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/scale'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/scale'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/scale'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/x_min'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/x_min'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/x_min'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/x_min'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/x_min'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/x_min'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
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
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain6'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain7'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain8'
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

  /*  Expression: inv([1 0 0; 0 1 1; 0 -0.4575 0.3875])
   * Referenced by: '<S5>/Inverse of T'
   */
  { 1.0, 0.0, 0.0, -0.0, 0.45857988165680474, 0.54142011834319526, -0.0,
    -1.1834319526627219, 1.1834319526627219 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_VSP2'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S4>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_VSP2'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/VSP_speed'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/VSP_speed'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/VSP_speed'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/VSP_speed'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/VSP_speed'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/VSP_speed'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/alpha_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/alpha_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/omega_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/u_BT'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/u_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/u_VSP2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S9>/Switch'
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
                                        * Referenced by: '<S3>/Dropout_detected'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Dropout_detected'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Dropout_detected'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Dropout_detected'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Dropout_detected'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Dropout_detected'
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

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
