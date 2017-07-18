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

#include <test/common/evaluator.h>

#include <service/logger.h>

template<typename T>
class CTestCase : CEvaluator::IEvaluatable<T>
{
public:
    CTestCase(ILogger& serviceLogger);
    virtual ~CTestCase();

protected:
    // Helpers: ILogger
    virtual void LogEol() final;
    virtual void Log(const char[], bool eol = true) final;
    virtual void Log(const int, ILogger::FORMAT = ILogger::FORMAT::DECIMAL, bool eol = true) final;
    virtual void Log(const long, ILogger::FORMAT = ILogger::FORMAT::DECIMAL, bool eol = true) final;
    virtual void Log(const unsigned int, ILogger::FORMAT = ILogger::FORMAT::DECIMAL, bool eol = true) final;
    virtual void Log(const unsigned long, ILogger::FORMAT = ILogger::FORMAT::DECIMAL, bool eol = true) final;

private:
    // Disable copying and assignments
    CTestCase(const CTestCase&);
    CTestCase& operator=(const CTestCase&);

    ILogger& m_service_logger;
};