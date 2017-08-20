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

#include <abdeveng/core/test/common/evaluator.h>

/* PUBLIC */

CEvaluator::CEvaluator() {
}

CEvaluator::~CEvaluator() {
}

void CEvaluator::SetDelValidateFail(CEvaluator::IDelValidateFail* delValidateFail) {
    m_del_validate_fail = delValidateFail;
}

bool CEvaluator::Validate(bool checkIfTrue) const {
    if (m_del_validate_fail != nullptr && !checkIfTrue) {
        m_del_validate_fail->OnValidateFail();
    }
    return checkIfTrue;
}

template<typename PRIMITIVE>
bool CEvaluator::Validate(PRIMITIVE actual, COMPARATOR comparator, PRIMITIVE expected) const {
    // TODO IMPLEMENT
    return false;
}

template<typename PRIMITIVE>
bool CEvaluator::Validate(EVALUATION<PRIMITIVE> evaluation, COMPARATOR comparator) const {
    // TODO IMPLEMENT
    return false;
}

/* FORWARD DECLARE FUNCTION TEMPLATES */
template bool CEvaluator::Validate<int8_t>(int8_t actual, COMPARATOR, int8_t expected) const;
template bool CEvaluator::Validate<int16_t>(int16_t actual, COMPARATOR, int16_t expected) const;
template bool CEvaluator::Validate<int32_t>(int32_t actual, COMPARATOR, int32_t expected) const;
template bool CEvaluator::Validate<uint8_t>(uint8_t actual, COMPARATOR, uint8_t expected) const;
template bool CEvaluator::Validate<uint16_t>(uint16_t actual, COMPARATOR, uint16_t expected) const;
template bool CEvaluator::Validate<uint32_t>(uint32_t actual, COMPARATOR, uint32_t expected) const;
template bool CEvaluator::Validate(EVALUATION<int8_t>, COMPARATOR) const;
template bool CEvaluator::Validate(EVALUATION<int16_t>, COMPARATOR) const;
template bool CEvaluator::Validate(EVALUATION<int32_t>, COMPARATOR) const;
template bool CEvaluator::Validate(EVALUATION<uint8_t>, COMPARATOR) const;
template bool CEvaluator::Validate(EVALUATION<uint16_t>, COMPARATOR) const;
template bool CEvaluator::Validate(EVALUATION<uint32_t>, COMPARATOR) const;
