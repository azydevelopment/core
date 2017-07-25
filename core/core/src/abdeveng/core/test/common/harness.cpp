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

CTestHarness::CTestHarness(CEvaluator& evaluator, ILogger& serviceLogger)
    : m_evaluator(evaluator)
    , m_service_logger(serviceLogger) {
}

CTestHarness::~CTestHarness() {
}

/* PROTECTED */

// Helpers: CEvaluator

CEvaluator::RESULT CTestHarness::Validate(CEvaluator::EVALUATION<bool> evaluation, CEvaluator::COMPARATOR comparator) const {
    return m_evaluator.Validate(evaluation, comparator);
}

CEvaluator::RESULT CTestHarness::Validate(CEvaluator::EVALUATION<int8_t> evaluation, CEvaluator::COMPARATOR comparator) const {
    return m_evaluator.Validate(evaluation, comparator);
}

CEvaluator::RESULT CTestHarness::Validate(CEvaluator::EVALUATION<int16_t> evaluation, CEvaluator::COMPARATOR comparator) const {
    return m_evaluator.Validate(evaluation, comparator);
}

CEvaluator::RESULT CTestHarness::Validate(CEvaluator::EVALUATION<int32_t> evaluation, CEvaluator::COMPARATOR comparator) const {
    return m_evaluator.Validate(evaluation, comparator);
}

// Helpers: ILogger

void CTestHarness::LogEol() {
    m_service_logger.LogEol();
}

void CTestHarness::Log(const char msg[], bool eol) {
    m_service_logger.Log(msg, eol);
}

void CTestHarness::Log(const int msg, ILogger::FORMAT format, bool eol) {
    m_service_logger.Log(msg, format, eol);
}

void CTestHarness::Log(const long msg, ILogger::FORMAT format, bool eol) {
    m_service_logger.Log(msg, format, eol);
}

void CTestHarness::Log(const unsigned int msg, ILogger::FORMAT format, bool eol) {
    m_service_logger.Log(msg, format, eol);
}

void CTestHarness::Log(const unsigned long msg, ILogger::FORMAT format, bool eol) {
    m_service_logger.Log(msg, format, eol);
}