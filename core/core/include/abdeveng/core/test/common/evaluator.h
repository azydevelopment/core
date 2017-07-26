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

class CEvaluator final
{
public:
    enum COMPARATOR : uint8_t
    {
        EQUAL,
        NOT_EQUAL,
        GREATER_THAN,
        GREATER_THAN_OR_EQUAL,
        LESS_THAN,
        LESS_THAN_OR_EQUAL
    };

    template<typename EVALUATION_PRIMITIVE>
    struct EVALUATION
    {
        // TODO IMPLEMENT: Do we want to limit the array index type to a uint8_t?
        EVALUATION_PRIMITIVE* payload_expected = nullptr;
        uint8_t len_payload_expected           = 0;
        EVALUATION_PRIMITIVE* payload_actual   = nullptr;
        uint8_t len_payload_actual             = 0;
    };

    class IDelCallbackValidation
    {
    public:
        virtual void OnValidationFail(bool actual, bool expected)       = 0;
        virtual void OnValidationFail(int8_t actual, int8_t expected)   = 0;
        virtual void OnValidationFail(int16_t actual, int16_t expected) = 0;
        virtual void OnValidationFail(int32_t actual, int32_t expected) = 0;
        virtual void OnValidationFail(const EVALUATION<bool>& evaluation)    = 0;
        virtual void OnValidationFail(const EVALUATION<int8_t>& evaluation)  = 0;
        virtual void OnValidationFail(const EVALUATION<int16_t>& evaluation) = 0;
        virtual void OnValidationFail(const EVALUATION<int32_t>& evaluation) = 0;
    };

    CEvaluator(IDelCallbackValidation&);
    virtual ~CEvaluator();

    bool Validate(bool checkIfTrue) const;

    template<typename PRIMITIVE>
    bool Validate(PRIMITIVE actual, COMPARATOR, PRIMITIVE expected) const;

    template<typename PRIMITIVE>
    bool Validate(EVALUATION<PRIMITIVE>, COMPARATOR) const;

private:
    IDelCallbackValidation& m_del_callback_validation;
};

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
