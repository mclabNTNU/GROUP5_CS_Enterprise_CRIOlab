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
 * Model version              : 1.90
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Feb 06 11:27:25 2017
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
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S1>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/counter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Hold'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S11>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S11>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S12>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S12>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S10>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S10>/White Noise'
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
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/ArrowRight'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */

  /*  Expression: inv([1/1.165 0 0; 0 1/1.165 1/2.629; 0 -0.4575/1.165 0.3875/2.629])
   * Referenced by: '<S2>/Inverse of T'
   */
  { 1.165, 0.0, 0.0, -0.0, 0.5342455621301776, 1.4233934911242603, -0.0,
    -1.3786982248520709, 3.1112426035502958 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/alpha_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/alpha_VSP2'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<S2>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/omega_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_VSP1'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/integrator reset model'
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
};

#endif
