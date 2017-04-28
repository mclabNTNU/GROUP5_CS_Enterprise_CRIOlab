/*
 * ctrl_student_HIL.c
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
  int_T nXc = 10;
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
  real_T rtb_Integrator[9];
  real_T *lastU;
  real_T psi_d;
  real_T psi_d_s;
  real_T R[9];
  real_T u_y_l;
  real_T u_y_r;
  static const real_T a[9] = { 0.059559261465157838, -0.0, 0.0, -0.0,
    0.063781377640431069, -0.012816359434559084, -0.0, -0.012816359434559084,
    0.36489418584869804 };

  static const real_T b_a[9] = { -0.059559261465157838, 0.0, -0.0, 0.0,
    -0.063781377640431069, 0.012816359434559084, 0.0, 0.012816359434559084,
    -0.36489418584869804 };

  boolean_T y;
  boolean_T exitg1;
  real_T rtb_TmpSignalConversionAtSFu_jn[3];
  real_T rtb_TmpSignalConversionAtSFun_c[3];
  real_T rtb_Sum;
  int32_T i;
  real_T tmp[3];
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T tmp_2[9];
  real_T tmp_3[3];
  real_T tmp_4[9];
  real_T R_0[3];
  real_T tmp_5[9];
  real_T tmp_6[9];
  real_T b_a_0[9];
  real_T a_0[9];
  real_T a_1[3];
  int32_T i_0;
  real_T b_a_1[3];
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

  /* Gain: '<S9>/Gain' */
  ctrl_student_HIL_B.Gain = ctrl_student_HIL_P.Gain_Gain_k *
    ctrl_student_HIL_B.X_pos;

  /* Gain: '<S9>/Gain1' */
  ctrl_student_HIL_B.Gain1 = ctrl_student_HIL_P.Gain1_Gain_i *
    ctrl_student_HIL_B.Y_pos;

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  rtb_Sum = ctrl_student_HIL_B.Psi_pos + ctrl_student_HIL_P.Constant2_Value;

  /* MATLAB Function: '<S9>/MATLAB Function' */
  /* MATLAB Function 'from ship/MATLAB Function': '<S30>:1' */
  if (!ctrl_student_HIL_DW.last_psi_not_empty) {
    /* '<S30>:1:4' */
    /* '<S30>:1:5' */
    ctrl_student_HIL_DW.last_psi = rtb_Sum;
    ctrl_student_HIL_DW.last_psi_not_empty = true;
  }

  if (rtb_Sum - ctrl_student_HIL_DW.last_psi <= -180.0) {
    /* '<S30>:1:7' */
    /* '<S30>:1:8' */
    rtb_Sum += 360.0;
  }

  if (rtb_Sum - ctrl_student_HIL_DW.last_psi >= 180.0) {
    /* '<S30>:1:11' */
    /* '<S30>:1:12' */
    rtb_Sum -= 360.0;
  }

  /* '<S30>:1:14' */
  ctrl_student_HIL_DW.last_psi = rtb_Sum;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtmeas_outInport1' incorporates:
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  /* '<S30>:1:15' */
  ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn[0] =
    ctrl_student_HIL_B.Gain;
  ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn[1] =
    ctrl_student_HIL_B.Gain1;
  ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn[2] = rtb_Sum;

  /* Gain: '<S9>/Gain2' incorporates:
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  ctrl_student_HIL_B.Gain2 = ctrl_student_HIL_P.Gain2_Gain * rtb_Sum;

  /* Integrator: '<S2>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_student_HIL_B.Model_reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator_CSTATE[0] = ctrl_student_HIL_B.Gain;
      ctrl_student_HIL_X.Integrator_CSTATE[1] = ctrl_student_HIL_B.Gain1;
      ctrl_student_HIL_X.Integrator_CSTATE[2] = ctrl_student_HIL_B.Gain2;

      {
        int_T i1;
        real_T *xc = &ctrl_student_HIL_X.Integrator_CSTATE[3];
        const real_T *u2 = &ctrl_student_HIL_P.Constant_Value[0];
        for (i1=0; i1 < 6; i1++) {
          xc[i1] = u2[i1];
        }
      }
    }
  }

  {
    int_T i1;
    real_T *y0 = &rtb_Integrator[0];
    real_T *xc = &ctrl_student_HIL_X.Integrator_CSTATE[0];
    for (i1=0; i1 < 9; i1++) {
      y0[i1] = xc[i1];
    }
  }

  /* Integrator: '<S14>/Integrator1' */
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

  /* MATLAB Function: '<S14>/eta_d_ellipsoid' */
  /* MATLAB Function 'Guidance and control/Guidance/eta_d_ellipsoid': '<S22>:1' */
  if (!ctrl_student_HIL_DW.psi_old_not_empty) {
    /* '<S22>:1:3' */
    /* '<S22>:1:4' */
    ctrl_student_HIL_DW.psi_old_not_empty = true;

    /* '<S22>:1:5' */
    ctrl_student_HIL_DW.psi_old = ctrl_student_HIL_B.ellipsoid_eta_0[2];
  }

  /* % eta_d */
  /* '<S22>:1:8' */
  /* '<S22>:1:9' */
  if (ctrl_student_HIL_B.ellipsoid_constant_heading_on_o != 0.0) {
    /* '<S22>:1:12' */
    psi_d = ctrl_student_HIL_B.ellipsoid_heading;
  } else {
    /* '<S22>:1:14' */
    psi_d = rt_atan2d_snf(ctrl_student_HIL_B.ellipsoid_r[1] * cos
                          (ctrl_student_HIL_B.Integrator1),
                          -ctrl_student_HIL_B.ellipsoid_r[0] * sin
                          (ctrl_student_HIL_B.Integrator1));

    /*      psi_d = atan(r(2)*cos(s)/(-r(1)*sin(s))); */
    if (psi_d < ctrl_student_HIL_DW.psi_old - 3.1415926535897931) {
      /* '<S22>:1:16' */
      /* '<S22>:1:17' */
      psi_d += 6.2831853071795862;
    }

    if (psi_d > ctrl_student_HIL_DW.psi_old + 3.1415926535897931) {
      /* '<S22>:1:19' */
      /* '<S22>:1:20' */
      psi_d += 6.2831853071795862;
    }

    /* '<S22>:1:22' */
    ctrl_student_HIL_DW.psi_old = psi_d;
  }

  /* '<S22>:1:24' */
  /* % eta_d_s */
  /* '<S22>:1:27' */
  /* '<S22>:1:28' */
  /* '<S22>:1:29' */
  rtb_Sum = 0.0;
  if (ctrl_student_HIL_B.ellipsoid_constant_heading_on_o != 0.0) {
    /* '<S22>:1:31' */
    psi_d_s = 0.0;
  } else {
    /* '<S22>:1:33' */
    rtb_Sum = ctrl_student_HIL_B.ellipsoid_r[0] * sin
      (ctrl_student_HIL_B.Integrator1);
    psi_d_s = ctrl_student_HIL_B.ellipsoid_r[1] * cos
      (ctrl_student_HIL_B.Integrator1);
    rtb_Sum = rtb_Sum * rtb_Sum + psi_d_s * psi_d_s;

    /* '<S22>:1:34' */
    psi_d_s = ctrl_student_HIL_B.ellipsoid_r[0] *
      ctrl_student_HIL_B.ellipsoid_r[1] / rtb_Sum;
  }

  /* '<S22>:1:36' */
  /* % eta_d_s_s */
  /* '<S22>:1:39' */
  /* '<S22>:1:40' */
  if (ctrl_student_HIL_B.ellipsoid_constant_heading_on_o != 0.0) {
    /* '<S22>:1:42' */
    rtb_Sum = 0.0;
  } else {
    /* '<S22>:1:44' */
    rtb_Sum = 2.0 * ctrl_student_HIL_B.ellipsoid_r[0] *
      ctrl_student_HIL_B.ellipsoid_r[1] * sin(ctrl_student_HIL_B.Integrator1) *
      cos(ctrl_student_HIL_B.Integrator1) * (ctrl_student_HIL_B.ellipsoid_r[1] *
      ctrl_student_HIL_B.ellipsoid_r[1] - ctrl_student_HIL_B.ellipsoid_r[0] *
      ctrl_student_HIL_B.ellipsoid_r[0]) / (rtb_Sum * rtb_Sum);
  }

  /* '<S22>:1:46' */

  /* Switch: '<S14>/Switch1' incorporates:
   *  Constant: '<S14>/Constant'
   *  MATLAB Function: '<S14>/eta_d_straightline'
   *  Switch: '<S14>/Switch'
   */
  /* MATLAB Function 'Guidance and control/Guidance/eta_d_straightline': '<S23>:1' */
  /* % eta_d */
  /* '<S23>:1:3' */
  /* '<S23>:1:4' */
  /* '<S23>:1:5' */
  /* '<S23>:1:6' */
  /* eta_d = [x_d; y_d; pi/4]; */
  /* % eta_d_s */
  /* '<S23>:1:10' */
  /* '<S23>:1:11' */
  /* '<S23>:1:12' */
  /* '<S23>:1:13' */
  /* % eta_d_s_s */
  /* '<S23>:1:16' */
  /* '<S23>:1:17' */
  /* '<S23>:1:18' */
  /* '<S23>:1:19' */
  if (ctrl_student_HIL_B.switch_keep_pos != 0.0) {
    ctrl_student_HIL_B.Switch1[0] = ctrl_student_HIL_B.pos[0];
    ctrl_student_HIL_B.Switch1[1] = ctrl_student_HIL_B.pos[1];
    ctrl_student_HIL_B.Switch1[2] = ctrl_student_HIL_B.pos[2];
    for (i = 0; i < 6; i++) {
      ctrl_student_HIL_B.Switch1[i + 3] = ctrl_student_HIL_P.Constant_Value_m[i];
    }
  } else if (ctrl_student_HIL_B.switch_straight_ellipsoid != 0.0) {
    /* Switch: '<S14>/Switch' incorporates:
     *  MATLAB Function: '<S14>/eta_d_ellipsoid'
     */
    ctrl_student_HIL_B.Switch1[0] = ctrl_student_HIL_B.ellipsoid_r[0] * cos
      (ctrl_student_HIL_B.Integrator1) + ctrl_student_HIL_B.ellipsoid_c[0];
    ctrl_student_HIL_B.Switch1[1] = ctrl_student_HIL_B.ellipsoid_r[1] * sin
      (ctrl_student_HIL_B.Integrator1) + ctrl_student_HIL_B.ellipsoid_c[1];
    ctrl_student_HIL_B.Switch1[2] = psi_d;
    ctrl_student_HIL_B.Switch1[3] = -ctrl_student_HIL_B.ellipsoid_r[0] * sin
      (ctrl_student_HIL_B.Integrator1);
    ctrl_student_HIL_B.Switch1[4] = ctrl_student_HIL_B.ellipsoid_r[1] * cos
      (ctrl_student_HIL_B.Integrator1);
    ctrl_student_HIL_B.Switch1[5] = psi_d_s;
    ctrl_student_HIL_B.Switch1[6] = -ctrl_student_HIL_B.ellipsoid_r[0] * cos
      (ctrl_student_HIL_B.Integrator1);
    ctrl_student_HIL_B.Switch1[7] = -ctrl_student_HIL_B.ellipsoid_r[1] * sin
      (ctrl_student_HIL_B.Integrator1);
    ctrl_student_HIL_B.Switch1[8] = rtb_Sum;
  } else {
    ctrl_student_HIL_B.Switch1[0] = (ctrl_student_HIL_B.straight_eta_d_1[0] -
      ctrl_student_HIL_B.straight_eta_d_0[0]) * ctrl_student_HIL_B.Integrator1 +
      ctrl_student_HIL_B.straight_eta_d_0[0];
    ctrl_student_HIL_B.Switch1[1] = (ctrl_student_HIL_B.straight_eta_d_1[1] -
      ctrl_student_HIL_B.straight_eta_d_0[1]) * ctrl_student_HIL_B.Integrator1 +
      ctrl_student_HIL_B.straight_eta_d_0[1];
    ctrl_student_HIL_B.Switch1[2] = rt_atan2d_snf
      (ctrl_student_HIL_B.straight_eta_d_1[1] -
       ctrl_student_HIL_B.straight_eta_d_0[1],
       ctrl_student_HIL_B.straight_eta_d_1[0] -
       ctrl_student_HIL_B.straight_eta_d_0[0]);
    ctrl_student_HIL_B.Switch1[3] = ctrl_student_HIL_B.straight_eta_d_1[0] -
      ctrl_student_HIL_B.straight_eta_d_0[0];
    ctrl_student_HIL_B.Switch1[4] = ctrl_student_HIL_B.straight_eta_d_1[1] -
      ctrl_student_HIL_B.straight_eta_d_0[1];
    ctrl_student_HIL_B.Switch1[5] = 0.0;
    ctrl_student_HIL_B.Switch1[6] = 0.0;
    ctrl_student_HIL_B.Switch1[7] = 0.0;
    ctrl_student_HIL_B.Switch1[8] = 0.0;
  }

  /* End of Switch: '<S14>/Switch1' */

  /* MATLAB Function: '<S13>/z_1' incorporates:
   *  Constant: '<S1>/Constant'
   *  SignalConversion: '<S19>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Guidance and control/Control/z_1': '<S19>:1' */
  /* '<S19>:1:2' */
  /* '<S19>:1:3' */
  /* '<S19>:1:4' */
  b_a_0[0] = cos(ctrl_student_HIL_P.Constant_Value_p);
  b_a_0[1] = -sin(ctrl_student_HIL_P.Constant_Value_p);
  b_a_0[2] = 0.0;
  b_a_0[3] = sin(ctrl_student_HIL_P.Constant_Value_p);
  b_a_0[4] = cos(ctrl_student_HIL_P.Constant_Value_p);
  b_a_0[5] = 0.0;
  b_a_0[6] = 0.0;
  b_a_0[7] = 0.0;
  b_a_0[8] = 1.0;
  psi_d = rtb_Integrator[0] - ctrl_student_HIL_B.Switch1[0];
  u_y_r = rtb_Integrator[1] - ctrl_student_HIL_B.Switch1[1];
  psi_d_s = ctrl_student_HIL_P.Constant_Value_p - ctrl_student_HIL_B.Switch1[2];
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.z_1[i] = 0.0;
    ctrl_student_HIL_B.z_1[i] += b_a_0[i] * psi_d;
    ctrl_student_HIL_B.z_1[i] += b_a_0[i + 3] * u_y_r;
    ctrl_student_HIL_B.z_1[i] += b_a_0[i + 6] * psi_d_s;
  }

  /* End of MATLAB Function: '<S13>/z_1' */

  /* MATLAB Function: '<S14>/update law' */
  /* MATLAB Function 'Guidance and control/Guidance/update law': '<S24>:1' */
  /* '<S24>:1:6' */
  psi_d_s = 2.2250738585072014E-308;
  psi_d = fabs(ctrl_student_HIL_B.Switch1[3]);
  if (psi_d > 2.2250738585072014E-308) {
    rtb_Sum = 1.0;
    psi_d_s = psi_d;
  } else {
    u_y_l = psi_d / 2.2250738585072014E-308;
    rtb_Sum = u_y_l * u_y_l;
  }

  psi_d = fabs(ctrl_student_HIL_B.Switch1[4]);
  if (psi_d > psi_d_s) {
    u_y_l = psi_d_s / psi_d;
    rtb_Sum = rtb_Sum * u_y_l * u_y_l + 1.0;
    psi_d_s = psi_d;
  } else {
    u_y_l = psi_d / psi_d_s;
    rtb_Sum += u_y_l * u_y_l;
  }

  rtb_Sum = psi_d_s * sqrt(rtb_Sum);
  u_y_r = fabs(ctrl_student_HIL_B.u_ref) / rtb_Sum;

  /* '<S24>:1:7' */
  /* '<S24>:1:8' */
  psi_d_s = 2.2250738585072014E-308;
  psi_d = fabs(ctrl_student_HIL_B.Switch1[3]);
  if (psi_d > 2.2250738585072014E-308) {
    rtb_Sum = 1.0;
    psi_d_s = psi_d;
  } else {
    u_y_l = psi_d / 2.2250738585072014E-308;
    rtb_Sum = u_y_l * u_y_l;
  }

  psi_d = fabs(ctrl_student_HIL_B.Switch1[4]);
  if (psi_d > psi_d_s) {
    u_y_l = psi_d_s / psi_d;
    rtb_Sum = rtb_Sum * u_y_l * u_y_l + 1.0;
    psi_d_s = psi_d;
  } else {
    u_y_l = psi_d / psi_d_s;
    rtb_Sum += u_y_l * u_y_l;
  }

  psi_d = fabs(ctrl_student_HIL_B.Switch1[5]);
  if (psi_d > psi_d_s) {
    u_y_l = psi_d_s / psi_d;
    rtb_Sum = rtb_Sum * u_y_l * u_y_l + 1.0;
    psi_d_s = psi_d;
  } else {
    u_y_l = psi_d / psi_d_s;
    rtb_Sum += u_y_l * u_y_l;
  }

  rtb_Sum = psi_d_s * sqrt(rtb_Sum);
  rtb_Sum = u_y_r - ((-(rtb_Integrator[0] - ctrl_student_HIL_B.Switch1[0]) *
                      ctrl_student_HIL_B.Switch1[3] + -(rtb_Integrator[1] -
    ctrl_student_HIL_B.Switch1[1]) * ctrl_student_HIL_B.Switch1[4]) +
                     -(rtb_Integrator[2] - ctrl_student_HIL_B.Switch1[2]) *
                     ctrl_student_HIL_B.Switch1[5]) * (ctrl_student_HIL_B.mu /
    rtb_Sum);

  /* % stop at end position or continue backwards */
  if (((ctrl_student_HIL_B.Integrator1 >= 1.0) || (ctrl_student_HIL_DW.backwards
        != 0.0)) && (!(ctrl_student_HIL_B.stop_at_pos != 0.0))) {
    /* '<S24>:1:11' */
    /* '<S24>:1:12' */
    ctrl_student_HIL_DW.backwards = 1.0;

    /* '<S24>:1:13' */
    rtb_Sum = -rtb_Sum;
    if (ctrl_student_HIL_B.Integrator1 <= 0.0) {
      /* '<S24>:1:14' */
      /* '<S24>:1:15' */
      ctrl_student_HIL_DW.backwards = 0.0;
    }
  }

  if ((ctrl_student_HIL_B.stop_at_pos != 0.0) && (ctrl_student_HIL_B.Integrator1
       >= 1.0)) {
    /* '<S24>:1:18' */
    /* '<S24>:1:19' */
    u_y_r = 0.0;

    /* '<S24>:1:20' */
    rtb_Sum = 0.0;
  }

  ctrl_student_HIL_B.s_dot = rtb_Sum;

  /* Switch: '<S14>/Switch2' incorporates:
   *  Constant: '<S14>/Constant1'
   *  MATLAB Function: '<S14>/update law'
   */
  if (ctrl_student_HIL_B.switch_keep_pos != 0.0) {
    ctrl_student_HIL_B.Switch2 = ctrl_student_HIL_P.Constant1_Value;
  } else {
    ctrl_student_HIL_B.Switch2 = u_y_r;
  }

  /* End of Switch: '<S14>/Switch2' */

  /* MATLAB Function: '<S13>/alfa1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  /* MATLAB Function 'Guidance and control/Control/alfa1': '<S16>:1' */
  /* '<S16>:1:2' */
  /* '<S16>:1:3' */
  /* '<S16>:1:4' */
  for (i = 0; i < 3; i++) {
    b_a_0[3 * i] = -ctrl_student_HIL_B.K_p[3 * i];
    b_a_0[1 + 3 * i] = -ctrl_student_HIL_B.K_p[3 * i + 1];
    b_a_0[2 + 3 * i] = -ctrl_student_HIL_B.K_p[3 * i + 2];
  }

  a_0[0] = cos(ctrl_student_HIL_P.Constant_Value_p);
  a_0[1] = -sin(ctrl_student_HIL_P.Constant_Value_p);
  a_0[2] = 0.0;
  a_0[3] = sin(ctrl_student_HIL_P.Constant_Value_p);
  a_0[4] = cos(ctrl_student_HIL_P.Constant_Value_p);
  a_0[5] = 0.0;
  a_0[6] = 0.0;
  a_0[7] = 0.0;
  a_0[8] = 1.0;
  for (i = 0; i < 3; i++) {
    tmp[i] = a_0[i + 6] * ctrl_student_HIL_B.Switch1[5] + (a_0[i + 3] *
      ctrl_student_HIL_B.Switch1[4] + a_0[i] * ctrl_student_HIL_B.Switch1[3]);
  }

  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.alfa1[i] = ((b_a_0[i + 3] * ctrl_student_HIL_B.z_1[1] +
      b_a_0[i] * ctrl_student_HIL_B.z_1[0]) + b_a_0[i + 6] *
      ctrl_student_HIL_B.z_1[2]) + tmp[i] * ctrl_student_HIL_B.Switch2;
  }

  /* End of MATLAB Function: '<S13>/alfa1' */

  /* MATLAB Function: '<S13>/z_2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  SignalConversion: '<S21>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Guidance and control/Control/z_2': '<S21>:1' */
  /* '<S21>:1:2' */
  ctrl_student_HIL_B.z_2[0] = rtb_Integrator[3] - ctrl_student_HIL_B.alfa1[0];
  ctrl_student_HIL_B.z_2[1] = rtb_Integrator[4] - ctrl_student_HIL_B.alfa1[1];
  ctrl_student_HIL_B.z_2[2] = ctrl_student_HIL_P.Constant1_Value_k -
    ctrl_student_HIL_B.alfa1[2];

  /* MATLAB Function 'Guidance and control/Control/D': '<S15>:1' */
  /* '<S15>:1:2' */
  /* '<S15>:1:3' */
  /* '<S15>:1:4' */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S15>:1:7' */
  /* '<S15>:1:11' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S15>:1:17' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Assembly of the damping matrix */
  /* '<S15>:1:24' */
  /* '<S15>:1:25' */
  /* '<S15>:1:26' */
  /*  using abs(r) */
  /* '<S15>:1:28' */
  /* '<S15>:1:29' */
  /* '<S15>:1:30' */
  /* '<S15>:1:32' */

  /* Switch: '<S14>/Switch3' incorporates:
   *  Constant: '<S14>/Constant2'
   */
  if (ctrl_student_HIL_B.switch_keep_pos != 0.0) {
    rtb_Sum = ctrl_student_HIL_P.Constant2_Value_l;
  } else {
    rtb_Sum = ctrl_student_HIL_B.s_dot;
  }

  /* End of Switch: '<S14>/Switch3' */

  /* SignalConversion: '<S20>/TmpSignal ConversionAt SFunction Inport2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  MATLAB Function: '<S13>/z_1_dot'
   */
  rtb_TmpSignalConversionAtSFun_c[0] = rtb_Integrator[3];
  rtb_TmpSignalConversionAtSFun_c[1] = rtb_Integrator[4];
  rtb_TmpSignalConversionAtSFun_c[2] = ctrl_student_HIL_P.Constant1_Value_k;

  /* Derivative: '<S13>/Derivative' */
  /* MATLAB Function 'Guidance and control/Control/z_1_dot': '<S20>:1' */
  /* '<S20>:1:2' */
  /* '<S20>:1:3' */
  /* '<S20>:1:4' */
  /* '<S20>:1:5' */
  /* '<S20>:1:6' */
  if ((ctrl_student_HIL_DW.TimeStampA >= ctrl_student_HIL_M->Timing.t[0]) &&
      (ctrl_student_HIL_DW.TimeStampB >= ctrl_student_HIL_M->Timing.t[0])) {
    ctrl_student_HIL_B.Derivative = 0.0;
  } else {
    psi_d_s = ctrl_student_HIL_DW.TimeStampA;
    lastU = &ctrl_student_HIL_DW.LastUAtTimeA;
    if (ctrl_student_HIL_DW.TimeStampA < ctrl_student_HIL_DW.TimeStampB) {
      if (ctrl_student_HIL_DW.TimeStampB < ctrl_student_HIL_M->Timing.t[0]) {
        psi_d_s = ctrl_student_HIL_DW.TimeStampB;
        lastU = &ctrl_student_HIL_DW.LastUAtTimeB;
      }
    } else {
      if (ctrl_student_HIL_DW.TimeStampA >= ctrl_student_HIL_M->Timing.t[0]) {
        psi_d_s = ctrl_student_HIL_DW.TimeStampB;
        lastU = &ctrl_student_HIL_DW.LastUAtTimeB;
      }
    }

    ctrl_student_HIL_B.Derivative = (ctrl_student_HIL_B.Switch2 - *lastU) /
      (ctrl_student_HIL_M->Timing.t[0] - psi_d_s);
  }

  /* End of Derivative: '<S13>/Derivative' */

  /* MATLAB Function: '<S13>/alfa1_dot' incorporates:
   *  Constant: '<S1>/Constant'
   */
  /* MATLAB Function 'Guidance and control/Control/alfa1_dot': '<S17>:1' */
  /* '<S17>:1:2' */
  /* '<S17>:1:3' */
  R[0] = cos(ctrl_student_HIL_P.Constant_Value_p);
  R[3] = -sin(ctrl_student_HIL_P.Constant_Value_p);
  R[6] = 0.0;
  R[1] = sin(ctrl_student_HIL_P.Constant_Value_p);
  R[4] = cos(ctrl_student_HIL_P.Constant_Value_p);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* MATLAB Function: '<S13>/D' incorporates:
   *  Constant: '<S1>/Constant1'
   *  SignalConversion: '<S15>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* '<S17>:1:4' */
  /* '<S17>:1:5' */
  /* '<S17>:1:6' */
  /* MATLAB Function 'Guidance and control/Control/tau': '<S18>:1' */
  /* '<S18>:1:2' */
  /* '<S18>:1:3' */
  /* '<S18>:1:5' */
  tmp_0[0] = (0.6555 - 0.3545 * rtb_Integrator[3]) - rtb_Integrator[3] *
    rtb_Integrator[3] * -3.787;
  tmp_0[3] = (-0.0 - -2.443 * rtb_Integrator[4]) - rtb_Integrator[4] *
    rtb_Integrator[4] * 0.0;
  tmp_0[6] = 0.0;
  tmp_0[1] = 0.0;
  tmp_0[4] = ((1.33 - -2.776 * rtb_Integrator[4]) - rtb_Integrator[4] *
              rtb_Integrator[4] * -64.91) - -0.805 * fabs
    (ctrl_student_HIL_P.Constant1_Value_k);
  tmp_0[7] = ((7.25 - -3.45 * fabs(ctrl_student_HIL_P.Constant1_Value_k)) -
              ctrl_student_HIL_P.Constant1_Value_k *
              ctrl_student_HIL_P.Constant1_Value_k * 0.0) - -0.845 * fabs
    (rtb_Integrator[4]);
  tmp_0[2] = 0.0;
  tmp_0[5] = ((-0.0 - -0.2088 * rtb_Integrator[4]) - rtb_Integrator[4] *
              rtb_Integrator[4] * 0.0) - 0.13 * fabs
    (ctrl_student_HIL_P.Constant1_Value_k);
  tmp_0[8] = ((1.9 - -0.75 * fabs(ctrl_student_HIL_P.Constant1_Value_k)) -
              ctrl_student_HIL_P.Constant1_Value_k *
              ctrl_student_HIL_P.Constant1_Value_k * 0.0) - 0.08 * fabs
    (rtb_Integrator[4]);

  /* MATLAB Function: '<S13>/z_1_dot' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   */
  tmp_1[0] = 0.0;
  tmp_1[3] = -ctrl_student_HIL_P.Constant1_Value_k;
  tmp_1[6] = 0.0;
  tmp_1[1] = ctrl_student_HIL_P.Constant1_Value_k;
  tmp_1[4] = 0.0;
  tmp_1[7] = 0.0;
  tmp_1[2] = 0.0;
  tmp_1[5] = 0.0;
  tmp_1[8] = 0.0;
  for (i = 0; i < 3; i++) {
    b_a_0[3 * i] = -tmp_1[3 * i];
    b_a_0[1 + 3 * i] = -tmp_1[3 * i + 1];
    b_a_0[2 + 3 * i] = -tmp_1[3 * i + 2];
  }

  tmp_2[0] = cos(ctrl_student_HIL_P.Constant_Value_p);
  tmp_2[1] = -sin(ctrl_student_HIL_P.Constant_Value_p);
  tmp_2[2] = 0.0;
  tmp_2[3] = sin(ctrl_student_HIL_P.Constant_Value_p);
  tmp_2[4] = cos(ctrl_student_HIL_P.Constant_Value_p);
  tmp_2[5] = 0.0;
  tmp_2[6] = 0.0;
  tmp_2[7] = 0.0;
  tmp_2[8] = 1.0;
  for (i = 0; i < 3; i++) {
    tmp[i] = tmp_2[i + 6] * ctrl_student_HIL_B.Switch1[5] + (tmp_2[i + 3] *
      ctrl_student_HIL_B.Switch1[4] + tmp_2[i] * ctrl_student_HIL_B.Switch1[3]);
  }

  /* MATLAB Function: '<S13>/alfa1_dot' */
  for (i = 0; i < 3; i++) {
    a_0[3 * i] = -ctrl_student_HIL_B.K_p[3 * i];
    a_0[1 + 3 * i] = -ctrl_student_HIL_B.K_p[3 * i + 1];
    a_0[2 + 3 * i] = -ctrl_student_HIL_B.K_p[3 * i + 2];
  }

  /* MATLAB Function: '<S13>/z_1_dot' incorporates:
   *  MATLAB Function: '<S13>/alfa1_dot'
   */
  for (i = 0; i < 3; i++) {
    tmp_3[i] = (((b_a_0[i + 3] * ctrl_student_HIL_B.z_1[1] + b_a_0[i] *
                  ctrl_student_HIL_B.z_1[0]) + b_a_0[i + 6] *
                 ctrl_student_HIL_B.z_1[2]) + rtb_TmpSignalConversionAtSFun_c[i])
      - tmp[i] * rtb_Sum;
  }

  /* MATLAB Function: '<S13>/alfa1_dot' incorporates:
   *  Constant: '<S1>/Constant1'
   *  MATLAB Function: '<S13>/tau'
   */
  tmp_4[0] = 0.0;
  tmp_4[3] = -ctrl_student_HIL_P.Constant1_Value_k;
  tmp_4[6] = 0.0;
  tmp_4[1] = 0.0;
  tmp_4[4] = ctrl_student_HIL_P.Constant1_Value_k;
  tmp_4[7] = 0.0;
  tmp_4[2] = 0.0;
  tmp_4[5] = 0.0;
  tmp_4[8] = 0.0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      b_a_0[i + 3 * i_0] = 0.0;
      b_a_0[i + 3 * i_0] += 0.0 * R[i_0];
      b_a_0[i + 3 * i_0] += tmp_4[i + 3] * R[i_0 + 3];
    }
  }

  for (i = 0; i < 3; i++) {
    tmp[i] = b_a_0[i + 6] * ctrl_student_HIL_B.Switch1[5] + (b_a_0[i + 3] *
      ctrl_student_HIL_B.Switch1[4] + b_a_0[i] * ctrl_student_HIL_B.Switch1[3]);
  }

  for (i = 0; i < 3; i++) {
    R_0[i] = R[3 * i + 2] * ctrl_student_HIL_B.Switch1[8] + (R[3 * i + 1] *
      ctrl_student_HIL_B.Switch1[7] + R[3 * i] * ctrl_student_HIL_B.Switch1[6]);
  }

  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtSFun_c[i] = R[3 * i + 2] *
      ctrl_student_HIL_B.Switch1[5] + (R[3 * i + 1] *
      ctrl_student_HIL_B.Switch1[4] + R[3 * i] * ctrl_student_HIL_B.Switch1[3]);
  }

  for (i = 0; i < 3; i++) {
    a_1[i] = ((((a_0[i + 3] * tmp_3[1] + a_0[i] * tmp_3[0]) + a_0[i + 6] *
                tmp_3[2]) - tmp[i] * ctrl_student_HIL_B.Switch2) + R_0[i] *
              rtb_Sum * ctrl_student_HIL_B.Switch2) +
      rtb_TmpSignalConversionAtSFun_c[i] * ctrl_student_HIL_B.Derivative;
  }

  /* MATLAB Function: '<S13>/tau' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant2'
   *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport5'
   */
  for (i = 0; i < 3; i++) {
    tmp[i] = ((tmp_0[i + 3] * ctrl_student_HIL_B.alfa1[1] + tmp_0[i] *
               ctrl_student_HIL_B.alfa1[0]) + tmp_0[i + 6] *
              ctrl_student_HIL_B.alfa1[2]) + (-ctrl_student_HIL_B.z_1[i] -
      ctrl_student_HIL_B.C_2 * ctrl_student_HIL_B.z_2[i]);
  }

  for (i = 0; i < 3; i++) {
    tmp_3[i] = ctrl_student_HIL_P.Par.Guidance.M[i + 6] * a_1[2] +
      (ctrl_student_HIL_P.Par.Guidance.M[i + 3] * a_1[1] +
       ctrl_student_HIL_P.Par.Guidance.M[i] * a_1[0]);
  }

  tmp_5[0] = cos(ctrl_student_HIL_P.Constant_Value_p);
  tmp_5[1] = -sin(ctrl_student_HIL_P.Constant_Value_p);
  tmp_5[2] = 0.0;
  tmp_5[3] = sin(ctrl_student_HIL_P.Constant_Value_p);
  tmp_5[4] = cos(ctrl_student_HIL_P.Constant_Value_p);
  tmp_5[5] = 0.0;
  tmp_5[6] = 0.0;
  tmp_5[7] = 0.0;
  tmp_5[8] = 1.0;
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.tau[i] = (tmp[i] + tmp_3[i]) - ((tmp_5[i + 3] *
      rtb_Integrator[7] + tmp_5[i] * rtb_Integrator[6]) + tmp_5[i + 6] *
      ctrl_student_HIL_P.Constant2_Value_k);
  }

  /*  ; */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/Gain1'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   */
  if (ctrl_student_HIL_B.enableController > ctrl_student_HIL_P.Switch_Threshold)
  {
    rtb_TmpSignalConversionAtSFu_jn[0] = ctrl_student_HIL_B.tau[0];
    rtb_TmpSignalConversionAtSFu_jn[1] = ctrl_student_HIL_B.tau[1];
    rtb_TmpSignalConversionAtSFu_jn[2] = ctrl_student_HIL_B.tau[2];
  } else {
    rtb_TmpSignalConversionAtSFu_jn[0] = (ctrl_student_HIL_P.Gain_Gain *
      ctrl_student_HIL_B.PosYRight + ctrl_student_HIL_P.Gain1_Gain *
      ctrl_student_HIL_B.PosYLeft) * (0.5 * ctrl_student_HIL_P.Par.Thrust_lim[0]);
    rtb_TmpSignalConversionAtSFu_jn[1] = 0.5 *
      ctrl_student_HIL_P.Par.Thrust_lim[1] * (ctrl_student_HIL_B.PosXRight +
      ctrl_student_HIL_B.PosXLeft);
    rtb_TmpSignalConversionAtSFu_jn[2] = 0.5 *
      ctrl_student_HIL_P.Par.Thrust_lim[2] * ctrl_student_HIL_P.Constant_Value_h;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLAB Function: '<S6>/MATLAB Function' */
  /* MATLAB Function 'Workspace saturation1/MATLAB Function': '<S29>:1' */
  /* '<S29>:1:3' */
  R[0] = cos(rtb_Integrator[2]);
  R[3] = sin(rtb_Integrator[2]);
  R[6] = 0.0;
  R[1] = -sin(rtb_Integrator[2]);
  R[4] = cos(rtb_Integrator[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* '<S29>:1:5' */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtSFun_c[i] = R[i + 6] *
      rtb_TmpSignalConversionAtSFu_jn[2] + (R[i + 3] *
      rtb_TmpSignalConversionAtSFu_jn[1] + R[i] *
      rtb_TmpSignalConversionAtSFu_jn[0]);
  }

  /* '<S29>:1:6' */
  psi_d = rtb_TmpSignalConversionAtSFun_c[0];
  u_y_r = rtb_TmpSignalConversionAtSFun_c[1];

  /* '<S29>:1:7' */
  /* check if x is above limits */
  if (rtb_Integrator[0] > ctrl_student_HIL_B.x_max) {
    /* '<S29>:1:10' */
    /* x is above of the limit */
    /* '<S29>:1:12' */
    rtb_Sum = (rtb_Integrator[0] - ctrl_student_HIL_B.x_max) *
      ctrl_student_HIL_B.scale;

    /* '<S29>:1:13' */
    psi_d = (1.0 - rtb_Sum) * rtb_TmpSignalConversionAtSFun_c[0] + -rtb_Sum;
  }

  /* check if x is below limits */
  if (rtb_Integrator[0] < ctrl_student_HIL_B.x_min) {
    /* '<S29>:1:16' */
    /* x is below of the limit */
    /* '<S29>:1:18' */
    rtb_Sum = (rtb_Integrator[0] - ctrl_student_HIL_B.x_min) *
      ctrl_student_HIL_B.scale;

    /* '<S29>:1:19' */
    psi_d = (1.0 + rtb_Sum) * rtb_TmpSignalConversionAtSFun_c[0] + -rtb_Sum;
  }

  /* check if y is above limits */
  if (rtb_Integrator[1] > ctrl_student_HIL_B.y_MAX) {
    /* '<S29>:1:22' */
    /* x is above of the limit */
    /* '<S29>:1:24' */
    rtb_Sum = (rtb_Integrator[1] - ctrl_student_HIL_B.y_MAX) *
      ctrl_student_HIL_B.scale;

    /* '<S29>:1:25' */
    u_y_r = (1.0 - rtb_Sum) * rtb_TmpSignalConversionAtSFun_c[1] + -rtb_Sum;
  }

  /* check if y is above limits */
  if (rtb_Integrator[1] < -ctrl_student_HIL_B.y_MAX) {
    /* '<S29>:1:28' */
    /* x is above of the limit */
    /* '<S29>:1:30' */
    rtb_Sum = (rtb_Integrator[1] - (-ctrl_student_HIL_B.y_MAX)) *
      ctrl_student_HIL_B.scale;

    /* '<S29>:1:31' */
    u_y_r = (1.0 + rtb_Sum) * rtb_TmpSignalConversionAtSFun_c[1] + -rtb_Sum;
  }

  /* Switch: '<S6>/Switch1' */
  /* '<S29>:1:33' */
  if (ctrl_student_HIL_B.Enable_W_sat != 0.0) {
    /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
     *  Saturate: '<S6>/Saturation'
     */
    for (i = 0; i < 3; i++) {
      R_0[i] = R[3 * i + 2] * rtb_TmpSignalConversionAtSFun_c[2] + (R[3 * i + 1]
        * u_y_r + R[3 * i] * psi_d);
    }

    /* Saturate: '<S6>/Saturation' incorporates:
     *  MATLAB Function: '<S6>/MATLAB Function'
     */
    if (R_0[0] > ctrl_student_HIL_P.Saturation_UpperSat[0]) {
      ctrl_student_HIL_B.Switch1_p[0] = ctrl_student_HIL_P.Saturation_UpperSat[0];
    } else if (R_0[0] < ctrl_student_HIL_P.Saturation_LowerSat[0]) {
      ctrl_student_HIL_B.Switch1_p[0] = ctrl_student_HIL_P.Saturation_LowerSat[0];
    } else {
      ctrl_student_HIL_B.Switch1_p[0] = R_0[0];
    }

    if (R_0[1] > ctrl_student_HIL_P.Saturation_UpperSat[1]) {
      ctrl_student_HIL_B.Switch1_p[1] = ctrl_student_HIL_P.Saturation_UpperSat[1];
    } else if (R_0[1] < ctrl_student_HIL_P.Saturation_LowerSat[1]) {
      ctrl_student_HIL_B.Switch1_p[1] = ctrl_student_HIL_P.Saturation_LowerSat[1];
    } else {
      ctrl_student_HIL_B.Switch1_p[1] = R_0[1];
    }

    if (R_0[2] > ctrl_student_HIL_P.Saturation_UpperSat[2]) {
      ctrl_student_HIL_B.Switch1_p[2] = ctrl_student_HIL_P.Saturation_UpperSat[2];
    } else if (R_0[2] < ctrl_student_HIL_P.Saturation_LowerSat[2]) {
      ctrl_student_HIL_B.Switch1_p[2] = ctrl_student_HIL_P.Saturation_LowerSat[2];
    } else {
      ctrl_student_HIL_B.Switch1_p[2] = R_0[2];
    }
  } else {
    ctrl_student_HIL_B.Switch1_p[0] = rtb_TmpSignalConversionAtSFu_jn[0];
    ctrl_student_HIL_B.Switch1_p[1] = rtb_TmpSignalConversionAtSFu_jn[1];
    ctrl_student_HIL_B.Switch1_p[2] = rtb_TmpSignalConversionAtSFu_jn[2];
  }

  /* End of Switch: '<S6>/Switch1' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAtx_hatInport1' incorporates:
   *  Gain: '<S7>/Gain6'
   *  Gain: '<S7>/Gain7'
   *  Gain: '<S7>/Gain8'
   */
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[0] = rtb_Integrator[0];
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[1] = rtb_Integrator[1];
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[2] =
    ctrl_student_HIL_P.Gain6_Gain * rtb_Integrator[2];
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[3] = rtb_Integrator[3];
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[4] = rtb_Integrator[4];
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[5] =
    ctrl_student_HIL_P.Gain7_Gain * rtb_Integrator[5];
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[6] = rtb_Integrator[6];
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[7] = rtb_Integrator[7];
  ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor[8] =
    ctrl_student_HIL_P.Gain8_Gain * rtb_Integrator[8];

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/Inverse of T'
   */
  /* MATLAB Function 'Thrust Allocation/MATLAB Function': '<S28>:1' */
  /* '<S28>:1:4' */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtSFu_jn[i] = ctrl_student_HIL_P.InverseofT_Value[i +
      6] * ctrl_student_HIL_B.Switch1_p[2] +
      (ctrl_student_HIL_P.InverseofT_Value[i + 3] *
       ctrl_student_HIL_B.Switch1_p[1] + ctrl_student_HIL_P.InverseofT_Value[i] *
       ctrl_student_HIL_B.Switch1_p[0]);
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  /* MATLAB Function 'Sixaxis2force/MATLAB Function1': '<S27>:1' */
  /* '<S27>:1:2' */
  rtb_Sum = sqrt(rtb_TmpSignalConversionAtSFu_jn[0] *
                 rtb_TmpSignalConversionAtSFu_jn[0] +
                 rtb_TmpSignalConversionAtSFu_jn[1] *
                 rtb_TmpSignalConversionAtSFu_jn[1]);
  i = 1;
  if (rtIsNaN(rtb_Sum)) {
    i = 2;
    rtb_Sum = 1.0;
  }

  if ((i < 2) && (1.0 < rtb_Sum)) {
    rtb_Sum = 1.0;
  }

  ctrl_student_HIL_B.u_VSP = rtb_Sum;

  /* '<S27>:1:3' */
  ctrl_student_HIL_B.alpha_VSP = rt_atan2d_snf(rtb_TmpSignalConversionAtSFu_jn[1],
    rtb_TmpSignalConversionAtSFu_jn[0]);

  /* '<S27>:1:4' */
  ctrl_student_HIL_B.u_BT = rtb_TmpSignalConversionAtSFu_jn[2];

  /* End of MATLAB Function: '<S4>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* MATLAB Function: '<S12>/Full thrust allocation4' incorporates:
   *  Constant: '<S12>/Constant'
   */
  /* MATLAB Function 'tau to real ship (only use in MCLab)/Full thrust allocation4': '<S33>:1' */
  /*  Forces and moments vector */
  /* '<S33>:1:8' */
  /*  Extended thrust configuration matrix */
  /*  Extended thrust coefficient matrix */
  /*  tau = T*K*u inverse */
  /* '<S33>:1:19' */
  psi_d_s = ctrl_student_HIL_B.Switch1_p[1] - ctrl_student_HIL_B.Switch1_p[0];
  psi_d = ((ctrl_student_HIL_B.Switch1_p[2] - ctrl_student_HIL_B.Switch1_p[0] *
            0.0) - psi_d_s * 0.11584699453551912) / 2.1857923497267762;
  psi_d_s -= psi_d * -18.867924528301888;
  rtb_Sum = psi_d_s / 8.6320754716981138;
  psi_d_s /= 8.6320754716981138;

  /* '<S33>:1:21' */
  psi_d_s = ((ctrl_student_HIL_B.Switch1_p[0] - psi_d * 9.433962264150944) -
             psi_d_s * -4.3160377358490569) / 0.5;

  /* '<S33>:1:22' */
  /* '<S33>:1:23' */
  u_y_l = psi_d / 2.0;

  /* '<S33>:1:24' */
  u_y_r = psi_d / 2.0;

  /* '<S33>:1:25' */
  psi_d = sqrt(rtb_Sum * rtb_Sum + u_y_r * u_y_r);

  /* '<S33>:1:26' */
  rtb_Sum = sqrt(psi_d_s * psi_d_s + u_y_l * u_y_l);

  /* '<S33>:1:27' */
  /* '<S33>:1:28' */
  /* '<S33>:1:30' */
  /* '<S33>:1:31' */
  if (ctrl_student_HIL_P.Constant_Value_o != 0.0) {
    /* '<S33>:1:34' */
    ctrl_student_HIL_B.omega_VSP = ctrl_student_HIL_B.VSP_speed;
  } else {
    /* '<S33>:1:36' */
    ctrl_student_HIL_B.omega_VSP = 0.0;
  }

  ctrl_student_HIL_B.u_VSP_r = 2.0 * psi_d / 1.165;
  ctrl_student_HIL_B.u_VSP_l = 2.0 * rtb_Sum / 1.165;
  ctrl_student_HIL_B.alpha_r = rt_atan2d_snf(u_y_r, psi_d);
  ctrl_student_HIL_B.alpha_l = rt_atan2d_snf(u_y_l, rtb_Sum);

  /* End of MATLAB Function: '<S12>/Full thrust allocation4' */

  /* MATLAB Function: '<S35>/control limit checking' incorporates:
   *  Constant: '<S12>/Constant1'
   *  SignalConversion: '<S36>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking': '<S36>:1' */
  /* '<S36>:1:2' */
  /* '<S36>:1:3' */
  /* '<S36>:1:4' */
  /* '<S36>:1:5' */
  /* '<S36>:1:6' */
  /* '<S36>:1:7' */
  /* '<S36>:1:8' */
  /* '<S36>:1:10' */
  /* '<S36>:1:18' */
  ctrl_student_HIL_B.fault = !((-1.0 <= ctrl_student_HIL_P.Constant1_Value_hi) &&
    (ctrl_student_HIL_P.Constant1_Value_hi <= 1.0) && (0.0 <=
    ctrl_student_HIL_B.u_VSP_l) && (ctrl_student_HIL_B.u_VSP_l <= 1.0) && (0.0 <=
    ctrl_student_HIL_B.u_VSP_r) && (ctrl_student_HIL_B.u_VSP_r <= 1.0) &&
    (-3.1415926535897931 <= ctrl_student_HIL_B.alpha_l) &&
    (ctrl_student_HIL_B.alpha_l <= 3.1415926535897931) && (-3.1415926535897931 <=
    ctrl_student_HIL_B.alpha_r) && (ctrl_student_HIL_B.alpha_r <=
    3.1415926535897931) && (-1.0 <= ctrl_student_HIL_B.omega_VSP) &&
    (ctrl_student_HIL_B.omega_VSP <= 1.0) && (-1.0 <=
    ctrl_student_HIL_B.omega_VSP) && (ctrl_student_HIL_B.omega_VSP <= 1.0));
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* MATLAB Function: '<S2>/Observer' incorporates:
   *  SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Luenberger Observer/Observer': '<S25>:1' */
  /* % eta bar */
  /* '<S25>:1:5' */
  /* '<S25>:1:6' */
  rtb_TmpSignalConversionAtSFu_jn[0] = ctrl_student_HIL_B.Gain - rtb_Integrator
    [0];
  rtb_TmpSignalConversionAtSFu_jn[1] = ctrl_student_HIL_B.Gain1 -
    rtb_Integrator[1];
  rtb_TmpSignalConversionAtSFu_jn[2] = ctrl_student_HIL_B.Gain2 -
    rtb_Integrator[2];

  /* '<S25>:1:8' */
  /* '<S25>:1:9' */
  /* Rotation matrix */
  /* '<S25>:1:11' */
  R[0] = cos(rtb_Integrator[2]);
  R[3] = -sin(rtb_Integrator[2]);
  R[6] = 0.0;
  R[1] = sin(rtb_Integrator[2]);
  R[4] = cos(rtb_Integrator[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S25>:1:17' */
  /* '<S25>:1:21' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S25>:1:27' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Assembly of the damping matrix */
  /* '<S25>:1:33' */
  /* '<S25>:1:34' */
  /* '<S25>:1:35' */
  /*  using abs(r) */
  /* '<S25>:1:37' */
  /* '<S25>:1:38' */
  /* '<S25>:1:39' */
  /* '<S25>:1:41' */
  /* % Dropout check */
  if (ctrl_student_HIL_B.Residual > ctrl_student_HIL_P.Switch_Threshold_m) {
    psi_d = ctrl_student_HIL_P.Constant_Value_k;
  } else {
    psi_d = ctrl_student_HIL_P.Constant1_Value_c;
  }

  /* End of Switch: '<S9>/Switch' */

  /* MATLAB Function: '<S2>/Observer' */
  if (psi_d == 1.0) {
    /* '<S25>:1:46' */
    /* '<S25>:1:47' */
    rtb_TmpSignalConversionAtSFu_jn[0] = 0.0;
    rtb_TmpSignalConversionAtSFu_jn[1] = 0.0;
    rtb_TmpSignalConversionAtSFu_jn[2] = 0.0;
  }

  /* % x_dot equations */
  /* '<S25>:1:51' */
  /* nu_hat_dot = M_inv*(-D*nu_hat + R'*(b_hat + L_2*eta_bar) + tau); */
  /* '<S25>:1:53' */
  /* '<S25>:1:54' */
  /* '<S25>:1:55' */
  for (i = 0; i < 3; i++) {
    R_0[i] = R[i + 6] * rtb_Integrator[5] + (R[i + 3] * rtb_Integrator[4] + R[i]
      * rtb_Integrator[3]);
  }

  for (i = 0; i < 3; i++) {
    tmp[i] = ctrl_student_HIL_B.L_1[i + 6] * rtb_TmpSignalConversionAtSFu_jn[2]
      + (ctrl_student_HIL_B.L_1[i + 3] * rtb_TmpSignalConversionAtSFu_jn[1] +
         ctrl_student_HIL_B.L_1[i] * rtb_TmpSignalConversionAtSFu_jn[0]);
  }

  tmp_6[0] = (0.6555 - 0.3545 * fabs(rtb_Integrator[3])) - rtb_Integrator[3] *
    rtb_Integrator[3] * -3.787;
  tmp_6[3] = (-0.0 - -2.443 * fabs(rtb_Integrator[4])) - rtb_Integrator[4] *
    rtb_Integrator[4] * 0.0;
  tmp_6[6] = 0.0;
  tmp_6[1] = 0.0;
  tmp_6[4] = ((1.33 - -2.776 * fabs(rtb_Integrator[4])) - rtb_Integrator[4] *
              rtb_Integrator[4] * -64.91) - -0.805 * fabs(rtb_Integrator[5]);
  tmp_6[7] = ((7.25 - -3.45 * fabs(rtb_Integrator[5])) - rtb_Integrator[5] *
              rtb_Integrator[5] * 0.0) - -0.845 * fabs(rtb_Integrator[4]);
  tmp_6[2] = 0.0;
  tmp_6[5] = ((-0.0 - -0.2088 * fabs(rtb_Integrator[4])) - rtb_Integrator[4] *
              rtb_Integrator[4] * 0.0) - 0.13 * fabs(rtb_Integrator[5]);
  tmp_6[8] = ((1.9 - -0.75 * fabs(rtb_Integrator[5])) - rtb_Integrator[5] *
              rtb_Integrator[5] * 0.0) - 0.08 * fabs(rtb_Integrator[4]);
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      b_a_0[i + 3 * i_0] = 0.0;
      b_a_0[i + 3 * i_0] += tmp_6[3 * i_0] * b_a[i];
      b_a_0[i + 3 * i_0] += tmp_6[3 * i_0 + 1] * b_a[i + 3];
      b_a_0[i + 3 * i_0] += tmp_6[3 * i_0 + 2] * b_a[i + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      a_0[i + 3 * i_0] = 0.0;
      a_0[i + 3 * i_0] += a[i] * R[i_0];
      a_0[i + 3 * i_0] += a[i + 3] * R[i_0 + 3];
      a_0[i + 3 * i_0] += a[i + 6] * R[i_0 + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtSFun_c[i] = b_a_0[i + 6] * rtb_Integrator[5] +
      (b_a_0[i + 3] * rtb_Integrator[4] + b_a_0[i] * rtb_Integrator[3]);
  }

  for (i = 0; i < 3; i++) {
    a_1[i] = a_0[i + 6] * rtb_Integrator[8] + (a_0[i + 3] * rtb_Integrator[7] +
      a_0[i] * rtb_Integrator[6]);
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      a_0[i + 3 * i_0] = 0.0;
      a_0[i + 3 * i_0] += a[i] * R[i_0];
      a_0[i + 3 * i_0] += a[i + 3] * R[i_0 + 3];
      a_0[i + 3 * i_0] += a[i + 6] * R[i_0 + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      b_a_0[i + 3 * i_0] = 0.0;
      b_a_0[i + 3 * i_0] += ctrl_student_HIL_B.L_2[3 * i_0] * a_0[i];
      b_a_0[i + 3 * i_0] += ctrl_student_HIL_B.L_2[3 * i_0 + 1] * a_0[i + 3];
      b_a_0[i + 3 * i_0] += ctrl_student_HIL_B.L_2[3 * i_0 + 2] * a_0[i + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    b_a_1[i] = ((b_a_0[i + 3] * rtb_TmpSignalConversionAtSFu_jn[1] + b_a_0[i] *
                 rtb_TmpSignalConversionAtSFu_jn[0]) + b_a_0[i + 6] *
                rtb_TmpSignalConversionAtSFu_jn[2]) +
      (rtb_TmpSignalConversionAtSFun_c[i] + a_1[i]);
  }

  for (i = 0; i < 3; i++) {
    a_1[i] = a[i + 6] * ctrl_student_HIL_B.Switch1_p[2] + (a[i + 3] *
      ctrl_student_HIL_B.Switch1_p[1] + a[i] * ctrl_student_HIL_B.Switch1_p[0]);
  }

  for (i = 0; i < 3; i++) {
    tmp_3[i] = ctrl_student_HIL_B.L_3[i + 6] * rtb_TmpSignalConversionAtSFu_jn[2]
      + (ctrl_student_HIL_B.L_3[i + 3] * rtb_TmpSignalConversionAtSFu_jn[1] +
         ctrl_student_HIL_B.L_3[i] * rtb_TmpSignalConversionAtSFu_jn[0]);
  }

  ctrl_student_HIL_B.x_hat_dot[0] = R_0[0] + tmp[0];
  ctrl_student_HIL_B.x_hat_dot[1] = R_0[1] + tmp[1];
  ctrl_student_HIL_B.x_hat_dot[2] = R_0[2] + tmp[2];
  ctrl_student_HIL_B.x_hat_dot[3] = b_a_1[0] + a_1[0];
  ctrl_student_HIL_B.x_hat_dot[4] = b_a_1[1] + a_1[1];
  ctrl_student_HIL_B.x_hat_dot[5] = b_a_1[2] + a_1[2];
  ctrl_student_HIL_B.x_hat_dot[6] = tmp_3[0];
  ctrl_student_HIL_B.x_hat_dot[7] = tmp_3[1];
  ctrl_student_HIL_B.x_hat_dot[8] = tmp_3[2];

  /* SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S3>/Detect droput'
   */
  rtb_TmpSignalConversionAtSFu_jn[0] = ctrl_student_HIL_B.Gain;
  rtb_TmpSignalConversionAtSFu_jn[1] = ctrl_student_HIL_B.Gain1;
  rtb_TmpSignalConversionAtSFu_jn[2] = ctrl_student_HIL_B.Gain2;

  /* MATLAB Function: '<S3>/Detect droput' incorporates:
   *  SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Signal Dropout detection/Detect droput': '<S26>:1' */
  if (!ctrl_student_HIL_DW.eta_old_not_empty) {
    /* '<S26>:1:3' */
    /* '<S26>:1:4' */
    ctrl_student_HIL_DW.eta_old[0] = ctrl_student_HIL_B.Gain;
    ctrl_student_HIL_DW.eta_old[1] = ctrl_student_HIL_B.Gain1;
    ctrl_student_HIL_DW.eta_old[2] = ctrl_student_HIL_B.Gain2;
    ctrl_student_HIL_DW.eta_old_not_empty = true;
  }

  y = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 3)) {
    if (!!(rtb_TmpSignalConversionAtSFu_jn[i] - ctrl_student_HIL_DW.eta_old[i] ==
           0.0)) {
      y = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (y) {
    /* '<S26>:1:7' */
    ctrl_student_HIL_B.dropout = 1.0;
  } else {
    /* '<S26>:1:9' */
    ctrl_student_HIL_B.dropout = 0.0;
  }

  /* '<S26>:1:11' */
  ctrl_student_HIL_DW.eta_old[0] = ctrl_student_HIL_B.Gain;
  ctrl_student_HIL_DW.eta_old[1] = ctrl_student_HIL_B.Gain1;
  ctrl_student_HIL_DW.eta_old[2] = ctrl_student_HIL_B.Gain2;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  real_T *lastU;

  /* Update for Integrator: '<S2>/Integrator' */
  ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 0;

  /* Update for Derivative: '<S13>/Derivative' */
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

  *lastU = ctrl_student_HIL_B.Switch2;

  /* End of Update for Derivative: '<S13>/Derivative' */
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

  /* Derivatives for Integrator: '<S14>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE = ctrl_student_HIL_B.s_dot;
  }
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for MATLAB Function: '<S9>/MATLAB Function' */
  ctrl_student_HIL_DW.last_psi_not_empty = false;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
    ctrl_student_HIL_X.Integrator_CSTATE[0] = 0.0;
    ctrl_student_HIL_X.Integrator_CSTATE[1] = 0.0;
    ctrl_student_HIL_X.Integrator_CSTATE[2] = 0.0;
    ctrl_student_HIL_X.Integrator_CSTATE[3] = 0.0;
    ctrl_student_HIL_X.Integrator_CSTATE[4] = 0.0;
    ctrl_student_HIL_X.Integrator_CSTATE[5] = 0.0;
    ctrl_student_HIL_X.Integrator_CSTATE[6] = 0.0;
    ctrl_student_HIL_X.Integrator_CSTATE[7] = 0.0;
    ctrl_student_HIL_X.Integrator_CSTATE[8] = 0.0;
  }

  ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S14>/Integrator1' */
  ctrl_student_HIL_X.Integrator1_CSTATE = (ctrl_student_HIL_P.Par.Guidance.s_0);

  /* InitializeConditions for MATLAB Function: '<S14>/eta_d_ellipsoid' */
  ctrl_student_HIL_DW.psi_old_not_empty = false;

  /* InitializeConditions for MATLAB Function: '<S14>/update law' */
  ctrl_student_HIL_DW.backwards = 0.0;

  /* InitializeConditions for Derivative: '<S13>/Derivative' */
  ctrl_student_HIL_DW.TimeStampA = (rtInf);
  ctrl_student_HIL_DW.TimeStampB = (rtInf);

  /* InitializeConditions for MATLAB Function: '<S3>/Detect droput' */
  ctrl_student_HIL_DW.eta_old_not_empty = false;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
    rtmSetFirstInitCond(ctrl_student_HIL_M, 0);
  }
}

/* Model terminate function */
void ctrl_student_HIL_terminate(void)
{
  /* (no terminate code required) */
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
  ctrl_student_HIL_M->Sizes.numContStates = (10);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (175);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (68);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (514);/* Sum of parameter "widths" */
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 43:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 51:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);

   case 52:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 53:
    return NIRT_GetValueByDataType(ptr,subindex,15,Complex);

   case 54:
    return NIRT_GetValueByDataType(ptr,subindex,16,Complex);

   case 55:
    return NIRT_GetValueByDataType(ptr,subindex,17,Complex);

   case 56:
    return NIRT_GetValueByDataType(ptr,subindex,20,Complex);

   case 57:
    return NIRT_GetValueByDataType(ptr,subindex,22,Complex);

   case 58:
    return NIRT_GetValueByDataType(ptr,subindex,24,Complex);

   case 59:
    return NIRT_GetValueByDataType(ptr,subindex,35,Complex);

   case 60:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 61:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);

   case 62:
    return NIRT_GetValueByDataType(ptr,subindex,35,Complex);

   case 63:
    return NIRT_GetValueByDataType(ptr,subindex,26,Complex);

   case 64:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 43:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 51:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);

   case 52:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 53:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,15,Complex);

   case 54:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,16,Complex);

   case 55:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,17,Complex);

   case 56:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,20,Complex);

   case 57:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,22,Complex);

   case 58:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,24,Complex);

   case 59:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,35,Complex);

   case 60:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 61:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);

   case 62:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,35,Complex);

   case 63:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,26,Complex);

   case 64:
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

  // from ship/X_pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.X_pos, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from ship/Y_pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Y_pos, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from ship/Psi_pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Psi_pos, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // from ship/Residual
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Residual, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Model_reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Model_reset, 0, data[index++], 0,
      0);
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

  // Guidance and control/Guidance/pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.pos, 0, data[index++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.pos, 1, data[index++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.pos, 2, data[index++], 25, 0);
  } else {
    index += 3;
  }

  // Guidance and control/Guidance/switch_keep_pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.switch_keep_pos, 0, data[index++],
      0, 0);
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
      0, data[index++], 52, 0);
  } else {
    index += 1;
  }

  // Guidance and control/Guidance/ellipsoid_heading
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ellipsoid_heading, 0, data[index
      ++], 52, 0);
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

  // Guidance and control/Guidance/straight_eta_d_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.straight_eta_d_1, 0, data[index
      ++], 14, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.straight_eta_d_1, 1, data[index
      ++], 14, 0);
  } else {
    index += 2;
  }

  // Guidance and control/Guidance/stop_at_pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.stop_at_pos, 0, data[index++], 0,
      0);
  } else {
    index += 1;
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.C_2, 0, data[index++], 52, 0);
  } else {
    index += 1;
  }

  // enableController
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.enableController, 0, data[index
      ++], 0, 0);
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
  if (TaskSampleHit[0]) {
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

  // Workspace saturation1/Enable_W_sat
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Enable_W_sat, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Workspace saturation1/x_max
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_max, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Workspace saturation1/y_MAX
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_MAX, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Workspace saturation1/scale
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.scale, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Workspace saturation1/x_min
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_min, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/VSP_speed
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.VSP_speed, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Luenberger Observer/L_1
  if (TaskSampleHit[0]) {
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
  if (TaskSampleHit[0]) {
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_B.L_3, count, data[index++], 18,
        0);
    }
  } else {
    index += 9;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 82;
}

double ni_extout[66];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // from ship/meas_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn,0,32,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn,1,32,0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn,2,32,0);
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

  // Guidance and control/Control/Z_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,0,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,1,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,2,25,0);
  } else {
    index += 3;
  }

  // Guidance and control/Control/Z_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_2,0,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_2,1,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_2,2,25,0);
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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,0,
      25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,1,
      25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,2,
      25,0);
  } else {
    index += 3;
  }

  // alpha: Virtual Signal # 0
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

  // tau_control: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,0,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,1,25,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,2,25,0);
  } else {
    index += 3;
  }

  // x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    for (count = 0; count < 9; count++) {
      ni_extout[index++] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor,count,30,0);
    }
  } else {
    index += 9;
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

  // eta_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,0,
      19,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,1,
      19,0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,2,
      19,0);
  } else {
    index += 3;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,0,
      25,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,2,
      25,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,1,
      25,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value_e,0,0,0);
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

  // tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.fault,0,8,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_l,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_r,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant1_Value_hi,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP_l,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP_r,0,0,
      0);
  } else {
    index += 1;
  }

  // Luenberger Observer/obs out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    for (count = 0; count < 9; count++) {
      ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.x_hat_dot,
        count,30,0);
    }
  } else {
    index += 9;
  }

  // Signal Dropout detection/Dropout_detected: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dropout,0,0,
      0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 66;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // from ship/meas_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn,0,32,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn,1,32,0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.TmpSignalConversionAtmeas_outIn,2,32,0);

  // Guidance and control/Control/alpha: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,2,25,0);

  // Guidance and control/Control/Z_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_1,2,25,0);

  // Guidance and control/Control/Z_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_2,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_2,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z_2,2,25,0);

  // Guidance and control/Guidance/s: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,0,
    0,0);

  // tau_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,0,
    25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,1,
    25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,2,
    25,0);

  // alpha: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alfa1,2,25,0);

  // tau_control: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,0,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,1,25,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.tau,2,25,0);

  // x_hat: Virtual Signal # 0
  for (count = 0; count < 9; count++) {
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.TmpSignalConversionAtx_hatInpor,count,30,0);
  }

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

  // eta_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,0,19,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,1,19,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1,2,19,
    0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,0,
    25,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,2,
    25,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Switch1_p,1,
    25,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value_e,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value_h,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Model_reset,0,
    0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.fault,0,8,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_l,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha_r,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,0,
    0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega_VSP,0,0,
    0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value_hi,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP_l,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP_r,0,0,0);

  // Luenberger Observer/obs out: Virtual Signal # 0
  for (count = 0; count < 9; count++) {
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.x_hat_dot,
      count,30,0);
  }

  // Signal Dropout detection/Dropout_detected: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.dropout,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil/Gain1/Gain", offsetof(P_ctrl_student_HIL_T, Par), 51, 1,
    2, 0, 0 },

  { 1, "ctrl_student_hil/Guidance and control/Control/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Par), 51, 1, 2, 2, 0 },

  { 2,
    "ctrl_student_hil/Guidance and control/Guidance/Integrator1/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Par), 51, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/joystick/Gain1/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain1_Gain), 52, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/joystick/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain), 52, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/Workspace saturation1/Saturation/UpperLimit", offsetof
    (P_ctrl_student_HIL_T, Saturation_UpperSat), 21, 3, 2, 10, 0 },

  { 6, "ctrl_student_hil/Workspace saturation1/Saturation/LowerLimit", offsetof
    (P_ctrl_student_HIL_T, Saturation_LowerSat), 21, 3, 2, 12, 0 },

  { 7, "ctrl_student_hil/from ship/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain_k), 52, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/from ship/Gain1/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain1_Gain_i), 52, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/from ship/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, Constant2_Value), 52, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil/from ship/Gain2/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain2_Gain), 52, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/Luenberger Observer/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value), 42, 6, 2, 22, 0 },

  { 12, "ctrl_student_hil/Guidance and control/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_p), 52, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil/Guidance and control/Guidance/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_m), 42, 6, 2, 26, 0 },

  { 14, "ctrl_student_hil/Guidance and control/Guidance/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 52, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil/Guidance and control/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, Constant1_Value_k), 52, 1, 2, 30, 0 },

  { 16, "ctrl_student_hil/Guidance and control/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, Constant2_Value_k), 52, 1, 2, 32, 0 },

  { 17, "ctrl_student_hil/Guidance and control/Guidance/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value_l), 52, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/Constant/Value", offsetof(P_ctrl_student_HIL_T,
    Constant_Value_h), 52, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil/Switch/Threshold", offsetof(P_ctrl_student_HIL_T,
    Switch_Threshold), 52, 1, 2, 38, 0 },

  { 20, "ctrl_student_hil/conversion to deg and mm/Gain6/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain6_Gain), 52, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/conversion to deg and mm/Gain7/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain7_Gain), 52, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil/conversion to deg and mm/Gain8/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain8_Gain), 52, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Thrust Allocation/Inverse of T/Value", offsetof
    (P_ctrl_student_HIL_T, InverseofT_Value), 18, 9, 2, 46, 0 },

  { 24, "ctrl_student_hil/Sixaxis2force/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_n), 52, 1, 2, 48, 0 },

  { 25,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value_e), 52, 1, 2, 50, 0 },

  { 26,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_i), 52, 1, 2, 52, 0 },

  { 27,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_h), 52, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil/tau to real ship (only use in MCLab)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_hi), 52, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/tau to real ship (only use in MCLab)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_o), 52, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/from ship/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_k), 52, 1, 2, 60, 0 },

  { 31, "ctrl_student_hil/from ship/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, Constant1_Value_c), 52, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil/from ship/Switch/Threshold", offsetof
    (P_ctrl_student_HIL_T, Switch_Threshold_m), 52, 1, 2, 64, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 33;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 3,                                /* Parameter at index 5 */
  1, 3,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  6, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  6, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  3, 3,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/from ship/X_pos", 0, "", offsetof(B_ctrl_student_HIL_T,
    X_pos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/from ship/Gain", 0, "", offsetof(B_ctrl_student_HIL_T,
    Gain)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/from ship/Y_pos", 0, "", offsetof(B_ctrl_student_HIL_T,
    Y_pos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/from ship/Gain1", 0, "", offsetof(B_ctrl_student_HIL_T,
    Gain1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/from ship/Psi_pos", 0, "", offsetof
    (B_ctrl_student_HIL_T, Psi_pos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0
  },

  { 5, "ctrl_student_hil/from ship/Residual", 0, "", offsetof
    (B_ctrl_student_HIL_T, Residual)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10,
    0 },

  { 6, "ctrl_student_hil/from ship/Gain2", 0, "", offsetof(B_ctrl_student_HIL_T,
    Gain2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/Model_reset", 0, "", offsetof(B_ctrl_student_HIL_T,
    Model_reset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, K_p)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 16, 0 },

  { 9, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, K_p)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 18, 0 },

  { 10, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(3,1)",
    offsetof(B_ctrl_student_HIL_T, K_p)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    20, 0 },

  { 11, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, K_p)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    22, 0 },

  { 12, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(2,2)",
    offsetof(B_ctrl_student_HIL_T, K_p)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    24, 0 },

  { 13, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(3,2)",
    offsetof(B_ctrl_student_HIL_T, K_p)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    26, 0 },

  { 14, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, K_p)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    28, 0 },

  { 15, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(2,3)",
    offsetof(B_ctrl_student_HIL_T, K_p)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    30, 0 },

  { 16, "ctrl_student_hil/Guidance and control/Control/K_p", 0, "(3,3)",
    offsetof(B_ctrl_student_HIL_T, K_p)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    32, 0 },

  { 17, "ctrl_student_hil/Guidance and control/Guidance/pos", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, pos)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    34, 0 },

  { 18, "ctrl_student_hil/Guidance and control/Guidance/pos", 0, "(2,1)",
    offsetof(B_ctrl_student_HIL_T, pos)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    36, 0 },

  { 19, "ctrl_student_hil/Guidance and control/Guidance/pos", 0, "(3,1)",
    offsetof(B_ctrl_student_HIL_T, pos)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    38, 0 },

  { 20, "ctrl_student_hil/Guidance and control/Guidance/switch_keep_pos", 0, "",
    offsetof(B_ctrl_student_HIL_T, switch_keep_pos)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/Guidance and control/Guidance/Integrator1", 0, "",
    offsetof(B_ctrl_student_HIL_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 42, 0 },

  { 22, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_r", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, ellipsoid_r)+0*sizeof(real_T), BLOCKIO_SIG,
    14, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_r", 0, "(2,1)",
    offsetof(B_ctrl_student_HIL_T, ellipsoid_r)+1*sizeof(real_T), BLOCKIO_SIG,
    14, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_c", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, ellipsoid_c)+0*sizeof(real_T), BLOCKIO_SIG,
    14, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_c", 0, "(2,1)",
    offsetof(B_ctrl_student_HIL_T, ellipsoid_c)+1*sizeof(real_T), BLOCKIO_SIG,
    14, 1, 2, 50, 0 },

  { 26,
    "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_constant_heading_on_off",
    0, "", offsetof(B_ctrl_student_HIL_T, ellipsoid_constant_heading_on_o)+0*
    sizeof(real_T), BLOCKIO_SIG, 52, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_heading", 0,
    "", offsetof(B_ctrl_student_HIL_T, ellipsoid_heading)+0*sizeof(real_T),
    BLOCKIO_SIG, 52, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_eta_0", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, ellipsoid_eta_0)+0*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_eta_0", 0,
    "(2,1)", offsetof(B_ctrl_student_HIL_T, ellipsoid_eta_0)+1*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/Guidance and control/Guidance/ellipsoid_eta_0", 0,
    "(3,1)", offsetof(B_ctrl_student_HIL_T, ellipsoid_eta_0)+2*sizeof(real_T),
    BLOCKIO_SIG, 25, 1, 2, 60, 0 },

  { 31,
    "ctrl_student_hil/Guidance and control/Guidance/switch_straight_ellipsoid",
    0, "", offsetof(B_ctrl_student_HIL_T, switch_straight_ellipsoid)+0*sizeof
    (real_T), BLOCKIO_SIG, 0, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil/Guidance and control/Guidance/straight_eta_d_0", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, straight_eta_d_0)+0*sizeof(real_T),
    BLOCKIO_SIG, 14, 1, 2, 64, 0 },

  { 33, "ctrl_student_hil/Guidance and control/Guidance/straight_eta_d_0", 0,
    "(2,1)", offsetof(B_ctrl_student_HIL_T, straight_eta_d_0)+1*sizeof(real_T),
    BLOCKIO_SIG, 14, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/Guidance and control/Guidance/straight_eta_d_1", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_T, straight_eta_d_1)+0*sizeof(real_T),
    BLOCKIO_SIG, 14, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/Guidance and control/Guidance/straight_eta_d_1", 0,
    "(2,1)", offsetof(B_ctrl_student_HIL_T, straight_eta_d_1)+1*sizeof(real_T),
    BLOCKIO_SIG, 14, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 72, 0 },

  { 37, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(2,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 74, 0 },

  { 38, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(3,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 76, 0 },

  { 39, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(4,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+3*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 78, 0 },

  { 40, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(5,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+4*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 80, 0 },

  { 41, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(6,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+5*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 82, 0 },

  { 42, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(7,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+6*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 84, 0 },

  { 43, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(8,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+7*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 86, 0 },

  { 44, "ctrl_student_hil/Guidance and control/Guidance/Switch1", 0, "(9,1)",
    offsetof(B_ctrl_student_HIL_T, Switch1)+8*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 88, 0 },

  { 45, "ctrl_student_hil/Guidance and control/Guidance/stop_at_pos", 0, "",
    offsetof(B_ctrl_student_HIL_T, stop_at_pos)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 90, 0 },

  { 46, "ctrl_student_hil/Guidance and control/Guidance/mu", 0, "", offsetof
    (B_ctrl_student_HIL_T, mu)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 92, 0 },

  { 47, "ctrl_student_hil/Guidance and control/Guidance/u_ref", 0, "", offsetof
    (B_ctrl_student_HIL_T, u_ref)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 94, 0
  },

  { 48, "ctrl_student_hil/Guidance and control/Guidance/Switch2", 0, "",
    offsetof(B_ctrl_student_HIL_T, Switch2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 96, 0 },

  { 49, "ctrl_student_hil/Guidance and control/Control/C_2", 0, "", offsetof
    (B_ctrl_student_HIL_T, C_2)+0*sizeof(real_T), BLOCKIO_SIG, 52, 1, 2, 98, 0 },

  { 50, "ctrl_student_hil/Guidance and control/Control/Derivative", 0, "",
    offsetof(B_ctrl_student_HIL_T, Derivative)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 100, 0 },

  { 51, "ctrl_student_hil/enableController", 0, "", offsetof
    (B_ctrl_student_HIL_T, enableController)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 102, 0 },

  { 52, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    104, 0 },

  { 53, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    106, 0 },

  { 54, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    108, 0 },

  { 55, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    110, 0 },

  { 56, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 112,
    0 },

  { 57, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 114,
    0 },

  { 58, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 116, 0 },

  { 59, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 118, 0 },

  { 60, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    120, 0 },

  { 61, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 122,
    0 },

  { 62, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    124, 0 },

  { 63, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    126, 0 },

  { 64, "ctrl_student_hil/Workspace saturation1/Enable_W_sat", 0, "", offsetof
    (B_ctrl_student_HIL_T, Enable_W_sat)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    128, 0 },

  { 65, "ctrl_student_hil/Workspace saturation1/x_max", 0, "", offsetof
    (B_ctrl_student_HIL_T, x_max)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 130, 0
  },

  { 66, "ctrl_student_hil/Workspace saturation1/y_MAX", 0, "", offsetof
    (B_ctrl_student_HIL_T, y_MAX)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 132, 0
  },

  { 67, "ctrl_student_hil/Workspace saturation1/scale", 0, "", offsetof
    (B_ctrl_student_HIL_T, scale)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 134, 0
  },

  { 68, "ctrl_student_hil/Workspace saturation1/x_min", 0, "", offsetof
    (B_ctrl_student_HIL_T, x_min)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 136, 0
  },

  { 69, "ctrl_student_hil/Workspace saturation1/Switch1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Switch1_p)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    138, 0 },

  { 70, "ctrl_student_hil/Workspace saturation1/Switch1", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, Switch1_p)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    140, 0 },

  { 71, "ctrl_student_hil/Workspace saturation1/Switch1", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, Switch1_p)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    142, 0 },

  { 72, "ctrl_student_hil/tau to real ship (only use in MCLab)/VSP_speed", 0, "",
    offsetof(B_ctrl_student_HIL_T, VSP_speed)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 144, 0 },

  { 73, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L_1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 146, 0
  },

  { 74, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L_1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 148, 0
  },

  { 75, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L_1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 150, 0
  },

  { 76, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, L_1)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 152, 0
  },

  { 77, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(2,2)", offsetof
    (B_ctrl_student_HIL_T, L_1)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 154, 0
  },

  { 78, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(3,2)", offsetof
    (B_ctrl_student_HIL_T, L_1)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 156, 0
  },

  { 79, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, L_1)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 158, 0
  },

  { 80, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(2,3)", offsetof
    (B_ctrl_student_HIL_T, L_1)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 160, 0
  },

  { 81, "ctrl_student_hil/Luenberger Observer/L_1", 0, "(3,3)", offsetof
    (B_ctrl_student_HIL_T, L_1)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 162, 0
  },

  { 82, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L_2)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 164, 0
  },

  { 83, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L_2)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 166, 0
  },

  { 84, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L_2)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 168, 0
  },

  { 85, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, L_2)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 170, 0
  },

  { 86, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(2,2)", offsetof
    (B_ctrl_student_HIL_T, L_2)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 172, 0
  },

  { 87, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(3,2)", offsetof
    (B_ctrl_student_HIL_T, L_2)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 174, 0
  },

  { 88, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, L_2)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 176, 0
  },

  { 89, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(2,3)", offsetof
    (B_ctrl_student_HIL_T, L_2)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 178, 0
  },

  { 90, "ctrl_student_hil/Luenberger Observer/L_2", 0, "(3,3)", offsetof
    (B_ctrl_student_HIL_T, L_2)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 180, 0
  },

  { 91, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, L_3)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 182, 0
  },

  { 92, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(2,1)", offsetof
    (B_ctrl_student_HIL_T, L_3)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 184, 0
  },

  { 93, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(3,1)", offsetof
    (B_ctrl_student_HIL_T, L_3)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 186, 0
  },

  { 94, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, L_3)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 188, 0
  },

  { 95, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(2,2)", offsetof
    (B_ctrl_student_HIL_T, L_3)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 190, 0
  },

  { 96, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(3,2)", offsetof
    (B_ctrl_student_HIL_T, L_3)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 192, 0
  },

  { 97, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, L_3)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 194, 0
  },

  { 98, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(2,3)", offsetof
    (B_ctrl_student_HIL_T, L_3)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 196, 0
  },

  { 99, "ctrl_student_hil/Luenberger Observer/L_3", 0, "(3,3)", offsetof
    (B_ctrl_student_HIL_T, L_3)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 198, 0
  },

  { 100,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation4",
    0, "u_VSP_r", offsetof(B_ctrl_student_HIL_T, u_VSP_r)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 200, 0 },

  { 101,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation4",
    1, "u_VSP_l", offsetof(B_ctrl_student_HIL_T, u_VSP_l)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 202, 0 },

  { 102,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation4",
    2, "alpha_r", offsetof(B_ctrl_student_HIL_T, alpha_r)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 204, 0 },

  { 103,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation4",
    3, "alpha_l", offsetof(B_ctrl_student_HIL_T, alpha_l)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 206, 0 },

  { 104,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Full thrust allocation4",
    4, "omega_VSP", offsetof(B_ctrl_student_HIL_T, omega_VSP)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 208, 0 },

  { 105, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 0, "u_VSP", offsetof
    (B_ctrl_student_HIL_T, u_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 210, 0
  },

  { 106, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 1, "alpha_VSP",
    offsetof(B_ctrl_student_HIL_T, alpha_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 212, 0 },

  { 107, "ctrl_student_hil/Sixaxis2force/MATLAB Function1", 2, "u_BT", offsetof
    (B_ctrl_student_HIL_T, u_BT)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 214, 0
  },

  { 108, "ctrl_student_hil/Signal Dropout detection/Detect droput", 0, "dropout",
    offsetof(B_ctrl_student_HIL_T, dropout)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 216, 0 },

  { 109, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,1)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+0*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 218, 0 },

  { 110, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,2)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+1*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 220, 0 },

  { 111, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,3)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+2*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 222, 0 },

  { 112, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,4)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+3*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 224, 0 },

  { 113, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,5)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+4*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 226, 0 },

  { 114, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,6)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+5*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 228, 0 },

  { 115, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,7)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+6*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 230, 0 },

  { 116, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,8)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+7*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 232, 0 },

  { 117, "ctrl_student_hil/Luenberger Observer/Observer", 0, "x_hat_dot(1,9)",
    offsetof(B_ctrl_student_HIL_T, x_hat_dot)+8*sizeof(real_T), BLOCKIO_SIG, 30,
    1, 2, 234, 0 },

  { 118, "ctrl_student_hil/Guidance and control/Guidance/update law", 0, "s_dot",
    offsetof(B_ctrl_student_HIL_T, s_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    236, 0 },

  { 119, "ctrl_student_hil/Guidance and control/Control/z_2", 0, "z_2(1,1)",
    offsetof(B_ctrl_student_HIL_T, z_2)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    238, 0 },

  { 120, "ctrl_student_hil/Guidance and control/Control/z_2", 0, "z_2(2,1)",
    offsetof(B_ctrl_student_HIL_T, z_2)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    240, 0 },

  { 121, "ctrl_student_hil/Guidance and control/Control/z_2", 0, "z_2(3,1)",
    offsetof(B_ctrl_student_HIL_T, z_2)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    242, 0 },

  { 122, "ctrl_student_hil/Guidance and control/Control/z_1", 0, "z_1(1,1)",
    offsetof(B_ctrl_student_HIL_T, z_1)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    244, 0 },

  { 123, "ctrl_student_hil/Guidance and control/Control/z_1", 0, "z_1(2,1)",
    offsetof(B_ctrl_student_HIL_T, z_1)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    246, 0 },

  { 124, "ctrl_student_hil/Guidance and control/Control/z_1", 0, "z_1(3,1)",
    offsetof(B_ctrl_student_HIL_T, z_1)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    248, 0 },

  { 125, "ctrl_student_hil/Guidance and control/Control/tau", 0, "tau(1,1)",
    offsetof(B_ctrl_student_HIL_T, tau)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    250, 0 },

  { 126, "ctrl_student_hil/Guidance and control/Control/tau", 0, "tau(2,1)",
    offsetof(B_ctrl_student_HIL_T, tau)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    252, 0 },

  { 127, "ctrl_student_hil/Guidance and control/Control/tau", 0, "tau(3,1)",
    offsetof(B_ctrl_student_HIL_T, tau)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1, 2,
    254, 0 },

  { 128, "ctrl_student_hil/Guidance and control/Control/alfa1", 0, "alfa1(1,1)",
    offsetof(B_ctrl_student_HIL_T, alfa1)+0*sizeof(real_T), BLOCKIO_SIG, 25, 1,
    2, 256, 0 },

  { 129, "ctrl_student_hil/Guidance and control/Control/alfa1", 0, "alfa1(2,1)",
    offsetof(B_ctrl_student_HIL_T, alfa1)+1*sizeof(real_T), BLOCKIO_SIG, 25, 1,
    2, 258, 0 },

  { 130, "ctrl_student_hil/Guidance and control/Control/alfa1", 0, "alfa1(3,1)",
    offsetof(B_ctrl_student_HIL_T, alfa1)+2*sizeof(real_T), BLOCKIO_SIG, 25, 1,
    2, 260, 0 },

  { 131,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking",
    0, "fault", offsetof(B_ctrl_student_HIL_T, fault)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 262, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 132;
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
  1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 76;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "from ship/X_pos", 0, EXT_IN, 1, 1, 1 },

  { 1, "from ship/Y_pos", 0, EXT_IN, 1, 1, 1 },

  { 2, "from ship/Psi_pos", 0, EXT_IN, 1, 1, 1 },

  { 3, "from ship/Residual", 0, EXT_IN, 1, 1, 1 },

  { 4, "Model_reset", 0, EXT_IN, 1, 1, 1 },

  { 5, "Guidance and control/Control/K_p", 0, EXT_IN, 9, 3, 3 },

  { 6, "Guidance and control/Guidance/pos", 0, EXT_IN, 3, 3, 1 },

  { 7, "Guidance and control/Guidance/switch_keep_pos", 0, EXT_IN, 1, 1, 1 },

  { 8, "Guidance and control/Guidance/ellipsoid_r", 0, EXT_IN, 2, 2, 1 },

  { 9, "Guidance and control/Guidance/ellipsoid_c", 0, EXT_IN, 2, 2, 1 },

  { 10, "Guidance and control/Guidance/ellipsoid_constant_heading_on_off", 0,
    EXT_IN, 1, 1, 1 },

  { 11, "Guidance and control/Guidance/ellipsoid_heading", 0, EXT_IN, 1, 1, 1 },

  { 12, "Guidance and control/Guidance/ellipsoid_eta_0", 0, EXT_IN, 3, 3, 1 },

  { 13, "Guidance and control/Guidance/switch_straight_ellipsoid", 0, EXT_IN, 1,
    1, 1 },

  { 14, "Guidance and control/Guidance/straight_eta_d_0", 0, EXT_IN, 2, 2, 1 },

  { 15, "Guidance and control/Guidance/straight_eta_d_1", 0, EXT_IN, 2, 2, 1 },

  { 16, "Guidance and control/Guidance/stop_at_pos", 0, EXT_IN, 1, 1, 1 },

  { 17, "Guidance and control/Guidance/mu", 0, EXT_IN, 1, 1, 1 },

  { 18, "Guidance and control/Guidance/u_ref", 0, EXT_IN, 1, 1, 1 },

  { 19, "Guidance and control/Control/C_2", 0, EXT_IN, 1, 1, 1 },

  { 20, "enableController", 0, EXT_IN, 1, 1, 1 },

  { 21, "joystick/L2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 22, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 23, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 24, "joystick/R2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 25, "joystick/PosXLeft", 0, EXT_IN, 1, 1, 1 },

  { 26, "joystick/PosYLeft", 0, EXT_IN, 1, 1, 1 },

  { 27, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 28, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 29, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 30, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 31, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 32, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 33, "Workspace saturation1/Enable_W_sat", 0, EXT_IN, 1, 1, 1 },

  { 34, "Workspace saturation1/x_max", 0, EXT_IN, 1, 1, 1 },

  { 35, "Workspace saturation1/y_MAX", 0, EXT_IN, 1, 1, 1 },

  { 36, "Workspace saturation1/scale", 0, EXT_IN, 1, 1, 1 },

  { 37, "Workspace saturation1/x_min", 0, EXT_IN, 1, 1, 1 },

  { 38, "tau to real ship (only use in MCLab)/VSP_speed", 0, EXT_IN, 1, 1, 1 },

  { 39, "Luenberger Observer/L_1", 0, EXT_IN, 9, 3, 3 },

  { 40, "Luenberger Observer/L_2", 0, EXT_IN, 9, 3, 3 },

  { 41, "Luenberger Observer/L_3", 0, EXT_IN, 9, 3, 3 },

  { 0, "from ship/meas_out", 0, EXT_OUT, 3, 3, 1 },

  { 1, "Guidance and control/Control/alpha", 0, EXT_OUT, 3, 3, 1 },

  { 2, "Guidance and control/Control/Z_1", 0, EXT_OUT, 3, 3, 1 },

  { 3, "Guidance and control/Control/Z_2", 0, EXT_OUT, 3, 3, 1 },

  { 4, "Guidance and control/Guidance/s", 0, EXT_OUT, 1, 1, 1 },

  { 5, "tau_out", 0, EXT_OUT, 3, 3, 1 },

  { 6, "alpha", 0, EXT_OUT, 3, 3, 1 },

  { 7, "tau_control", 0, EXT_OUT, 3, 3, 1 },

  { 8, "x_hat", 0, EXT_OUT, 9, 9, 1 },

  { 9, "Sixaxis2force/alpha_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Sixaxis2force/alpha_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Sixaxis2force/omega_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 12, "Sixaxis2force/omega_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 13, "Sixaxis2force/u_BT", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Sixaxis2force/u_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 15, "Sixaxis2force/u_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 16, "eta_d", 0, EXT_OUT, 3, 3, 1 },

  { 17, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 18, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 19, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 20, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 21, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 22, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 23, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

  { 24,
    "tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds",
    0, EXT_OUT, 1, 1, 1 },

  { 25,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 26,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 27,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 28,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 29, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT",
    1, EXT_OUT, 1, 1, 1 },

  { 30, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 31, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 32, "Luenberger Observer/obs out", 0, EXT_OUT, 9, 9, 1 },

  { 33, "Signal Dropout detection/Dropout_detected", 0, EXT_OUT, 1, 1, 1 },

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
static char* NI_CompiledModelVersion = "1.271";
static char* NI_CompiledModelDateTime = "Fri Apr 28 12:01:18 2017";
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
      *numContStates = 10;
      *numDiscStates = 1533;
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
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_pos_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_pos_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Psi_pos_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Psi_pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.meas_out_DWORK1, 0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.meas_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.meas_out_DWORK1, 1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.meas_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.meas_out_DWORK1, 2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.meas_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Residual_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Residual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Model_reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Model_reset_DWORK1");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p_DWORK1,
        count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.pos_DWORK1, 0,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.pos_DWORK1, 1,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.pos_DWORK1, 2,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.switch_keep_pos_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.switch_keep_pos_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1, 0, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1, 1, 28, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.stop_at_pos_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.stop_at_pos_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_1_DWORK1, 0,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_1_DWORK1, 1,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_1_DWORK1, 2,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_2_DWORK1, 0,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_2_DWORK1, 1,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_2_DWORK1, 2,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_DWORK1");
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
      (&ctrl_student_HIL_DW.enableController_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.enableController_DWORK1");
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
      (&ctrl_student_HIL_DW.Enable_W_sat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Enable_W_sat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_max_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_max_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_MAX_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_MAX_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.scale_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.scale_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_min_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_min_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_DWORK1_g, 0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_DWORK1_g, 1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_DWORK1_g, 2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_DWORK1_g");
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
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_hat_DWORK1, count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_hat_DWORK1");
    }

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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1,
      0, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1,
      1, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1,
      2, 32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_d_DWORK1");
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
      (&ctrl_student_HIL_DW.VSP_speed_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.VSP_speed_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP1_DWORK1_g, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP1_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP2_DWORK1_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP2_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP1_DWORK1_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP1_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP2_DWORK1_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP2_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1_c,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_VSP1_DWORK1_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_VSP1_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_VSP2_DWORK1_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_VSP2_DWORK1_o");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L_1_DWORK1,
        count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L_1_DWORK1");
    }

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

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.obsout_DWORK1, count, 30, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.obsout_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Dropout_detected_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Dropout_detected_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.last_psi, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.last_psi");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 0,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 1,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_old, 2,
      32, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.backwards, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.backwards");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_old, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_old");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK,
      0, 11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Scope_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.X_pos_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.X_pos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Y_pos_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Y_pos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Psi_pos_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Psi_pos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.meas_out_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.meas_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Residual_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Residual_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Model_reset_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Model_reset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.pos_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.pos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.switch_keep_pos_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.switch_keep_pos_DWORK2");
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
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.straight_eta_d_1_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.straight_eta_d_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.stop_at_pos_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.stop_at_pos_DWORK2");
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
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_1_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_2_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.enableController_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.enableController_DWORK2");
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
        (&ctrl_student_HIL_DW.Enable_W_sat_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Enable_W_sat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_max_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_max_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.y_MAX_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.y_MAX_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.scale_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.scale_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_min_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_min_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_out_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_DWORK2_k, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_DWORK2_k");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_control_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_control_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_hat_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_hat_DWORK2");
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
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_d_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_d_DWORK2");
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
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.VSP_speed_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.VSP_speed_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_h, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_h");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2_b, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2_b");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2_l, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2_l");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2_p, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2_p");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2_h, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2_h");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_BT_DWORK2_e, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_BT_DWORK2_e");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2_k, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2_k");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2_l, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2_l");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L_1_DWORK2,
        count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L_1_DWORK2");
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
        (&ctrl_student_HIL_DW.obsout_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.obsout_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Dropout_detected_DWORK2, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Dropout_detected_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.last_psi_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.last_psi_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_old_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_old_not_empty");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_old_not_empty, 0, 8, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_old_not_empty");
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
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_pos_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_pos_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Psi_pos_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.meas_out_DWORK1, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.meas_out_DWORK1, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.meas_out_DWORK1, 2,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Residual_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Model_reset_DWORK1, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.pos_DWORK1, 0, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.pos_DWORK1, 1, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.pos_DWORK1, 2, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.switch_keep_pos_DWORK1, 0,
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1, 0,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_1_DWORK1, 1,
      discStates[idx++], 28, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.stop_at_pos_DWORK1, 0,
      discStates[idx++], 0, 0);
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_1_DWORK1, 0, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_1_DWORK1, 1, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_1_DWORK1, 2, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_2_DWORK1, 0, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_2_DWORK1, 1, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_2_DWORK1, 2, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TimeStampA, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.LastUAtTimeA, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.TimeStampB, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.LastUAtTimeB, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.enableController_DWORK1, 0,
      discStates[idx++], 0, 0);
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_W_sat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_max_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_MAX_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.scale_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_min_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK1, 2,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1_g, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1_g, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK1_g, 2,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_control_DWORK1, 0,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_control_DWORK1, 1,
      discStates[idx++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_control_DWORK1, 2,
      discStates[idx++], 32, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK1, count,
        discStates[idx++], 30, 0);
    }

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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1, 0, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1, 1, discStates[idx
      ++], 32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK1, 2, discStates[idx
      ++], 32, 0);
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.VSP_speed_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK1_g, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK1_i, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK1_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK1_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1_i, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1_o, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_1_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_2_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_3_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.obsout_DWORK1, count,
        discStates[idx++], 30, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_detected_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.last_psi, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 0, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 1, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old, 2, discStates[idx++],
      32, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.backwards, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_old, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Scope_PWORK, 0, discStates[idx
      ++], 11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Integrator_IWORK.IcNeedsLoading,
      0, discStates[idx++], 10, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_pos_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_pos_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Psi_pos_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.meas_out_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Residual_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Model_reset_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.pos_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.switch_keep_pos_DWORK2, count,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.straight_eta_d_1_DWORK2,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.stop_at_pos_DWORK2, count,
        discStates[idx++], 38, 0);
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_1_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_2_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.enableController_DWORK2,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Enable_W_sat_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_max_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_MAX_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.scale_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_min_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_out_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_DWORK2_k, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_control_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK2, count,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_DWORK2, count,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.VSP_speed_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_h, count,
         discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2_b, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2_l, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2_p, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2_h, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2_e, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2_k, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2_l, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L_1_DWORK2, count,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.obsout_DWORK2, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_detected_DWORK2,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 38, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 40, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.last_psi_not_empty, 0,
      discStates[idx++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_old_not_empty, 0,
      discStates[idx++], 8, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_old_not_empty, 0,
      discStates[idx++], 8, 0);
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
