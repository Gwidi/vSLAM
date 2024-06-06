//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_testyCodegena_info.cpp
//
// Code generation for function 'testyCodegena'
//

// Include files
#include "_coder_testyCodegena_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

// Function Definitions
static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4]{
      "789ce5533d4bc34018be4815976a2677a14e42020aee520864302a298a14c1ebf5b447ef"
      "a324d7183747b7aeeefe09277f9bcdc7e50b8e848a2ebe439e3c79b8"
      "7b9e7bdf1c30dc0b0300b007b27addc9b09f7333c72d50afa66e6850d536e8d5d6297d95"
      "23125ce258668443868b9553c108875c8e5e161804381434c2d35479",
      "24148f08c37e957809634e452a482225efc31946737fc940300bcb84b44a8a7ebc6bcedb"
      "ebd88f134d3fcc863e7687f70306258593400839b0a5107422623b22"
      "21115c01135c442185cc62f59c6f3fcc79d49253e9590e8baca7157048ad2c4cfaf42594"
      "cb301d5399eb61c35ccdd2e552a5fc3e37f453fb5fb7f8297dec7a5d",
      "e675ac50356cfd25e995dde8981a676bdff63b9e43770ffb6037c5c38f2ff4977eaafe8b"
      "5facd9afeb7f78a0f1331bfae5d3e9cd9933f7048a6ed1b97f8716f0"
      "d973ca1c572d3e6d398086fff6fedf28267a56",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1688U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9]{"Version",
                                 "ResolvedFunctions",
                                 "Checksum",
                                 "EntryPoints",
                                 "CoverageInfo",
                                 "IsPolymorphic",
                                 "PropertyList",
                                 "UUID",
                                 "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8]{
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 13);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("testyCodegena"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(13.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString("/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                          "ciowy/vSLAM/test/testyCodegena.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739400.92048611108));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.1.0.2603908 (R2024a) Update 3"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("zgcqjSn6k2I5jvPA4JQzTF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

// End of code generation (_coder_testyCodegena_info.cpp)
