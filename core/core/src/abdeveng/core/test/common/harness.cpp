/* The MIT License (MIT)
*
* Copyright (c) 2017 Andrew Yeung/Bhavya Kashyap <ab.deveng@gmail.com>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE. */

#include <abdeveng/core/test/common/harness.h>

#include <abdeveng/core/test/common/evaluator.h>

/* PUBLIC */

template<typename DUT_TYPE>
CTestHarness<DUT_TYPE>::CTestHarness(DUT_TYPE& dut, ILogger& logger)
    : m_del_callback_validation(CTestHarness::CDelCallbackValidation(logger))
    , m_evaluator(CEvaluator(m_del_callback_validation))
    , m_logger(logger) {
}

template<typename DUT_TYPE>
CTestHarness<DUT_TYPE>::~CTestHarness() {
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::Run() {
    // TODO HACK: Limited to 256 test cases
    uint8_t numTestCases = GetNumTestCases();
    for (uint8_t i = 0; i < numTestCases; i++) {
        // TODO IMPLEMENT: Print test start metadata
        ResetDUT();
        GetTestCase(i, m_evaluator).Run(m_dut);
        // TODO IMPLEMENT: Print test pass/fail metadata
    }
}

/* PROTECTED */

template<typename DUT_TYPE>
CEvaluator& CTestHarness<DUT_TYPE>::GetEvaluator() {
    return m_evaluator;
}

// Helpers: ILogger

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::Log(const char msg[], bool eol) {
    m_logger.Log(msg, eol);
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::Log(const int msg, ILogger::FORMAT format, bool eol) {
    m_logger.Log(msg, format, eol);
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::Log(const long msg, ILogger::FORMAT format, bool eol) {
    m_logger.Log(msg, format, eol);
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::Log(const unsigned int msg, ILogger::FORMAT format, bool eol) {
    m_logger.Log(msg, format, eol);
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::Log(const unsigned long msg, ILogger::FORMAT format, bool eol) {
    m_logger.Log(msg, format, eol);
}

/* PRIVATE */

// CTestHarness<DUT_TYPE>::CDelCallbackValidation

template<typename DUT_TYPE>
CTestHarness<DUT_TYPE>::CDelCallbackValidation::CDelCallbackValidation(ILogger& logger)
    : m_logger(logger) {
}

template<typename DUT_TYPE>
CTestHarness<DUT_TYPE>::CDelCallbackValidation::~CDelCallbackValidation() {
}

// CTestHarness<DUT_TYPE>::CDelCallbackValidation::CEvaluator::IDelCallbackValidation

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::CDelCallbackValidation::OnValidationFail(bool expected, bool actual) {
    // TODO IMPLEMENT
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::CDelCallbackValidation::OnValidationFail(int8_t expected, int8_t actual) {
    // TODO IMPLEMENT
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::CDelCallbackValidation::OnValidationFail(int16_t expected, int16_t actual) {
    // TODO IMPLEMENT
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::CDelCallbackValidation::OnValidationFail(int32_t expected, int32_t actual) {
    // TODO IMPLEMENT
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::CDelCallbackValidation::OnValidationFail(const CEvaluator::EVALUATION<bool>& evaluation) {
    // TODO IMPLEMENT
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::CDelCallbackValidation::OnValidationFail(const CEvaluator::EVALUATION<int8_t>& evaluation) {
    // TODO IMPLEMENT
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::CDelCallbackValidation::OnValidationFail(const CEvaluator::EVALUATION<int16_t>& evaluation) {
    // TODO IMPLEMENT
}

template<typename DUT_TYPE>
void CTestHarness<DUT_TYPE>::CDelCallbackValidation::OnValidationFail(const CEvaluator::EVALUATION<int32_t>& evaluation) {
    // TODO IMPLEMENT
}
