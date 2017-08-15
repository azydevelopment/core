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
        // print test header
        GetLogger().Log("\n----------------");
        GetLogger().Log("Test #", false);
        GetLogger().Log(i);
        GetLogger().Log("----------------");

        // only enable logging from the test when logging verbose
        GetLogger().SetEnabledLogger(IsVerboseLogging());

        // reset the failed last test flag
        SetFailedLastTest(false);

        // run the test
        GetTestCase(i).Run(dut, GetTestCaseConfig(i), GetEvaluator(), GetLogger());

        // reenable the logger if it was off
        GetLogger().SetEnabledLogger(true);

        // print test result
        GetLogger().Log("----------------");
        GetLogger().Log("Test result: ", false);
        if (IsFailedLastTest()) {
            GetLogger().Log("FAIL");
        } else {
            GetLogger().Log("PASS");
        }
    }
}

void CTestHarness::SetFailedLastTest(bool failed) {
    m_failed_last_test = failed;
}

bool CTestHarness::IsFailedLastTest() {
    return m_failed_last_test;
}

// CEvaluator::IDelValidateFail

void CTestHarness::OnValidateFail() {
    m_failed_last_test = true;
}

/* PRIVATE */

volatile void* CTestHarness::GetDUT() {
    return m_test_harness_config.dut;
}

ILogger& CTestHarness::GetLogger() {
    return *m_test_harness_config.logger;
}

bool CTestHarness::IsVerboseLogging() {
    return m_test_harness_config.verbose_logging;
}

const CEvaluator& CTestHarness::GetEvaluator() {
    m_evaluator.SetDelValidateFail(this);
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