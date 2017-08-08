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

#include <abdeveng/core/service/logger.h>

/* PUBLIC */

CTestHarness::CTestHarness() {
}

CTestHarness::~CTestHarness() {
}

void CTestHarness::Run() {
    volatile void* dut = GetDUT();

    // TODO HACK: Limited to 256 test cases
    uint8_t numTestCases = GetNumTestCases();

    // TODO HACK: Limited to 256 test cases
    for (uint8_t i = 0; i < numTestCases; i++) {
        // TODO IMPLEMENT: Print test start metadata
        GetTestCase(i).Run(dut, GetTestCaseConfig(i), GetEvaluator(), GetLogger());
        // TODO IMPLEMENT: Print test pass/fail metadata
    }
}

/* PRIVATE */

volatile void* CTestHarness::GetDUT() {
    return m_test_harness_config.dut;
}

ILogger& CTestHarness::GetLogger() {
    return *m_test_harness_config.logger;
}

const CEvaluator& CTestHarness::GetEvaluator() {
    return m_evaluator;
}

uint8_t CTestHarness::GetNumTestCases() {
    return m_test_playlist.num_test_cases;
}

CTestHarness::ITestCase& CTestHarness::GetTestCase(uint8_t testIndex) {
    // TODO ERROR_HANDLING: No nullptr check?
    return *m_test_playlist.test_cases[testIndex];
}

const CTestHarness::ITestCase::TEST_CASE_CONFIG_DESC& CTestHarness::GetTestCaseConfig(uint8_t testIndex) {
    // TODO ERROR_HANDLING: No nullptr check?
    return *m_test_playlist.test_case_configs[testIndex];
}