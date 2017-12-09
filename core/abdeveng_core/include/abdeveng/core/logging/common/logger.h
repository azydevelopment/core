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

class CLogger
{
public:
    // destructor
    virtual ~CLogger();

    // NVI
    virtual void Init() final;
    virtual void SetEnabled(const bool) final;
    virtual bool IsEnabled() final;
    virtual void LogEol() final;
    virtual void Log(const char[], const bool eol = true) final;

protected:
    // constructor
    CLogger();

private:
    // rule of three
    CLogger(const CLogger&);
    CLogger& operator=(const CLogger&);

    // member variables
    bool m_enabled;

    // abstract
    virtual void Init_impl()                 = 0;
    virtual void SetEnabled_impl(const bool) = 0;
    virtual void Log_impl(const char[], const bool eol = true) = 0;
};