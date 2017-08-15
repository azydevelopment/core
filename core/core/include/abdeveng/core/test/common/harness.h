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

#pragma once

#include <stdint.h>

#include <abdeveng/core/test/common/evaluator.h>

class ILogger;

class CTestHarness final : CEvaluator::IDelValidateFail
{
public:
    class ITestCase
    {
    public:
        virtual ~ITestCase() {
        }

        struct TEST_CASE_CONFIG_DESC
        {};

        virtual void Run(volatile void* dut, const TEST_CASE_CONFIG_DESC&, const CEvaluator&, const ILogger&) = 0;
    };

    struct TEST_HARNESS_CONFIG_DESC
    {
        volatile void* dut   = nullptr;
        ILogger* logger      = nullptr;
        bool verbose_logging = true;
    };

    struct TEST_PLAYLIST_DESC
    {
        // TODO HACK: Limited to 256 test cases
        uint8_t num_test_cases                               = 0;
        ITestCase** test_cases                               = nullptr;
        ITestCase::TEST_CASE_CONFIG_DESC** test_case_configs = nullptr;
    };

    CTestHarness();
    virtual ~CTestHarness();

    virtual void SetTestHarnessConfig(const TEST_HARNESS_CONFIG_DESC&);
    virtual void SetTestPlaylist(const TEST_PLAYLIST_DESC&);
    virtual void Run() final;
    virtual void SetFailedLastTest(bool failed);
    virtual bool IsFailedLastTest();

    // CEvaluator::IDelValidateFail
    virtual void OnValidateFail();

private:
    virtual volatile void* GetDUT();
    virtual bool IsVerboseLogging();
    virtual ILogger& GetLogger();
    virtual const CEvaluator& GetEvaluator();
    virtual uint8_t GetNumTestCases();
    virtual ITestCase& GetTestCase(uint8_t testIndex);
    virtual const ITestCase::TEST_CASE_CONFIG_DESC& GetTestCaseConfig(uint8_t testIndex);

    TEST_HARNESS_CONFIG_DESC m_test_harness_config;
    TEST_PLAYLIST_DESC m_test_playlist;

    CEvaluator m_evaluator;
    bool m_failed_last_test;
};