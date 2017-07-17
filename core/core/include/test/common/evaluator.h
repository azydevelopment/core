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
    enum TYPE : uint8_t
    {
        BOOL  = 0,
        INT8  = 0,
        INT16 = INT8 + 1,
        INT32 = INT16 + 1
    };

    enum RESULT : uint8_t
    {
        PASS = 0,
        FAIL = 1,
        // TODO IMPLEMENT: Maybe use UINT8_MAX. Is that a standard define?
        UNDEFINED = 255
    };

    template<typename T>
    struct EVALUATION final
    {
        // TODO IMPLEMENT: Do we want to limit the array index type to a uint8_t?
        T* const payload_expected    = nullptr;
        uint8_t len_payload_expected = 0;
        T* const payload_actual      = nullptr;
        uint8_t len_payload_actual   = 0;
    };

    template<typename U>
    class IEvaluatable
    {
    public:
        virtual ~IEvaluatable(){};

        virtual TYPE GetType() const                  = 0;
        virtual uint8_t GetEvaluationLength() const   = 0; // TODO: Do we want to limit the array index to a uint8_t
        virtual EVALUATION<U> Evaluate(EVALUATION<U>) = 0;
    };

    CEvaluator();
    virtual ~CEvaluator();

    // TODO IMPLEMENT: Any reason to not make these static?
    // TODO IMPLEMENT: Maybe inline even? Gotta trade off binary size with perf.
    RESULT Validate(EVALUATION<int8_t>) const;
    RESULT Validate(EVALUATION<int16_t>) const;
    RESULT Validate(EVALUATION<int32_t>) const;
};
