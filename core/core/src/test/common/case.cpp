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

#include <test/common/case.h>

/* PUBLIC */

template<typename EVALUATION_PRIMITIVE>
CTestCase<typename EVALUATION_PRIMITIVE>::CTestCase(ILogger& serviceLogger)
    : m_service_logger(serviceLogger) {
}

template<typename EVALUATION_PRIMITIVE>
CTestCase<typename EVALUATION_PRIMITIVE>::~CTestCase() {
}

/* PROTECTED */

// Helpers: ILogger

template<typename EVALUATION_PRIMITIVE>
void CTestCase<typename EVALUATION_PRIMITIVE>::LogEol() {
    m_service_logger.LogEol();
}

template<typename EVALUATION_PRIMITIVE>
void CTestCase<typename EVALUATION_PRIMITIVE>::Log(const char msg[], bool eol) {
    m_service_logger.Log(msg, eol);
}

template<typename EVALUATION_PRIMITIVE>
void CTestCase<typename EVALUATION_PRIMITIVE>::Log(const int msg, ILogger::FORMAT format, bool eol) {
    m_service_logger.Log(msg, format, eol);
}

template<typename EVALUATION_PRIMITIVE>
void CTestCase<typename EVALUATION_PRIMITIVE>::Log(const long msg, ILogger::FORMAT format, bool eol) {
    m_service_logger.Log(msg, format, eol);
}

template<typename EVALUATION_PRIMITIVE>
void CTestCase<typename EVALUATION_PRIMITIVE>::Log(const unsigned int msg, ILogger::FORMAT format, bool eol) {
    m_service_logger.Log(msg, format, eol);
}

template<typename EVALUATION_PRIMITIVE>
void CTestCase<typename EVALUATION_PRIMITIVE>::Log(const unsigned long msg, ILogger::FORMAT format, bool eol) {
    m_service_logger.Log(msg, format, eol);
}

/* FORWARD DECLARED TEMPLATE COMBOS */
template class CTestCase<bool>;
template class CTestCase<int8_t>;
template class CTestCase<int16_t>;
template class CTestCase<int32_t>;