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

#include <abdeveng/core/logging/common/logger.h>

/* PUBLIC */

CTestHarness::CTestHarness() {
    m_evaluator.SetDelValidateFail(this);
}

CTestHarness::~CTestHarness() {
}

void CTestHarness::SetTestHarnessConfig(const TEST_HARNESS_CONFIG_DESC& config) {
    m_test_harness_config = config;
}

void CTestHarness::SetTestPlaylist(const TEST_PLAYLIST_DESC& playlist) {
    m_test_playlist = playlist;
}

void CTestHarness::Run() {
    volatile void* dut = GetDUT();

    // TODO HACK: Limited to 256 test cases
    uint8_t numTestCases = GetNumTestCases();

    // TODO HACK: Limited to 256 test cases
    for (uint8_t i = 0; i < numTestCases; i++) {
        // print test header
        GetLogger().Log("\n----------------");
        GetLogger().Log("Test start");
        GetLogger().Log("----------------");

        // only enable logging from the test when logging verbose
        GetLogger().SetEnabled(IsVerboseLogging());

        // reset the failed last test flag
        SetFailedLastTest(false);

        // run the test
        GetTestCase(i).Run(dut, GetTestCaseConfig(i), GetEvaluator(), GetLogger());

        // reenable the logger if it was off
        GetLogger().SetEnabled(true);

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

bool CTestHarness::IsFailedLastTest() const {
    return m_failed_last_test;
}

// CEvaluator::IDelValidateFail

void CTestHarness::OnValidateFail() {
    m_failed_last_test = true;
}

/* PRIVATE */

volatile void* CTestHarness::GetDUT() const {
    return m_test_harness_config.dut;
}

CLogger& CTestHarness::GetLogger() const {
    return *m_test_harness_config.logger;
}

bool CTestHarness::IsVerboseLogging() const {
    return m_test_harness_config.verbose_logging;
}

const CEvaluator& CTestHarness::GetEvaluator() const {
    return m_evaluator;
}

uint8_t CTestHarness::GetNumTestCases() const {
    return m_test_playlist.num_test_cases;
}

CTestHarness::ITestCase& CTestHarness::GetTestCase(uint8_t testIndex) const {
    // TODO ERROR_HANDLING: No nullptr check?
    return *m_test_playlist.test_cases[testIndex];
}

const CTestHarness::ITestCase::TEST_CASE_CONFIG_DESC&
CTestHarness::GetTestCaseConfig(uint8_t testIndex) const {
    // TODO ERROR_HANDLING: No nullptr check?
    return *m_test_playlist.test_case_configs[testIndex];
}