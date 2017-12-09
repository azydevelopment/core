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

    class IDelValidateFail
    {
    public:
        virtual void OnValidateFail() = 0;
    };

    CEvaluator();
    ~CEvaluator();

    void SetDelValidateFail(IDelValidateFail*);

    bool Validate(bool checkIfTrue) const;

    template<typename PRIMITIVE>
    bool Validate(PRIMITIVE actual, COMPARATOR, PRIMITIVE expected) const;

    template<typename PRIMITIVE>
    bool Validate(EVALUATION<PRIMITIVE>&, COMPARATOR) const;

private:
    IDelValidateFail* m_del_validate_fail;
};