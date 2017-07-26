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

#include <abdeveng/core/test/common/case.h>

/* PUBLIC */

template<typename DUT_TYPE>
CTestCase<DUT_TYPE>::CTestCase(CEvaluator& evaluator)
    : m_evaluator(evaluator) {
}

template<typename DUT_TYPE>
CTestCase<DUT_TYPE>::~CTestCase() {
}

/* PROTECTED */

// Helpers: CEvaluator

template<typename DUT_TYPE>
bool CTestCase<DUT_TYPE>::Validate(bool checkIfTrue) const {
    return m_evaluator.Validate(checkIfTrue);
}

template<typename DUT_TYPE>
template<typename PRIMITIVE>
bool CTestCase<DUT_TYPE>::Validate(PRIMITIVE actual, CEvaluator::COMPARATOR comparator, PRIMITIVE expected) const {
    return m_evaluator.Validate<PRIMITIVE>(actual, comparator, expected);
}

template<typename DUT_TYPE>
template<typename PRIMITIVE>
bool CTestCase<DUT_TYPE>::Validate(CEvaluator::EVALUATION<PRIMITIVE> evaluation, CEvaluator::COMPARATOR comparator) const {
    return m_evaluator.Validate<PRIMITIVE>(evaluation, comparator);
}