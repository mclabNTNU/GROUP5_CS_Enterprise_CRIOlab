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
 * Model version              : 1.172
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Feb 21 16:43:38 2017
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
    1.0,

    {
      { 0.0, 0.0 },
      2.0,
      5.0,
      5.0,
      -5.0,
      5.0,
      -5.0,
      -3.0,
      3.0,
      -3.0,
      3.0
    },

    {
      0.0,
      2.0,
      3.0
    },
    0.01,

    { 1.03, 2.5, 0.98 },

    {
      { 0.059559261465157838, 0.0, 0.0, 0.0, 0.063781377640431069,
        -0.012816359434559084, 0.0, -0.012816359434559084, 0.36489418584869804 },

      { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    }
  },                                   /* Variable: Par
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<S1>/Constant'
                                        *   '<S7>/Constant'
                                        *   '<S7>/Constant1'
                                        *   '<S7>/Constant2'
                                        *   '<S7>/Constant3'
                                        *   '<S7>/Constant4'
                                        *   '<S7>/Constant5'
                                        *   '<S26>/Constant'
                                        *   '<S26>/Integrator'
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
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S11>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Noise_Power'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Noise_Power'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Noise_Power'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Noise_Power'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Noise_Power'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Noise_Power'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S24>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S24>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S25>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_e
                                        * Referenced by: '<S25>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S25>/White Noise'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S23>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S23>/White Noise'
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
                                        * Referenced by: '<S19>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Enable_Noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Enable_Noise'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Enable_Noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Enable_Noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Enable_Noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Enable_Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_m'
                                        */
  2.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
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
  3.0,                                 /* Expression: portnum
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

  /*  Expression: inv([1 0 0; 0 1 1; 0 -0.4575 0.3875])
   * Referenced by: '<S6>/Inverse of T'
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
                                        * Referenced by: '<S2>/nu_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/nu_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/nu_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/nu_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/nu_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/nu_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/eta_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/eta_hat'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/eta_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/eta_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/eta_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/eta_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/b_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/b_hat'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/b_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/b_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/b_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/b_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/eta_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/eta_tilde'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/eta_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/eta_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/eta_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/eta_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/nu_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/nu_tilde'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/nu_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/nu_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/nu_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/nu_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_1_1 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_1_1 '
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_1_1 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_1_1 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_1_1 '
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_1_1 '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_1_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_1_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_1_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_1_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_1_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_1_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_1_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_1_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_1_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_1_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_1_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_1_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_2_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_2_2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_2_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_2_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_2_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_2_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_2_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_2_1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_2_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_2_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_2_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_2_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_2_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_2_3'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_2_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_2_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_2_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_2_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_3_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_3_1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_3_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_3_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_3_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_3_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_3_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_3_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_3_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_3_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_3_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_3_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/L_3_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/L_3_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/L_3_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/L_3_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/L_3_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/L_3_3'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
