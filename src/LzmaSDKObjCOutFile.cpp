/*
 *   Copyright (c) 2015 Kulykov Oleh <info@resident.name>
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *   THE SOFTWARE.
 */


#include "LzmaSDKObjCOutFile.h"
#include <unistd.h>

namespace LzmaSDKObjC
{

	STDMETHODIMP OutFile::Write(const void *data, UInt32 size, UInt32 *processedSize)
	{
		fprintf(stdout, "OutFile::Write = %u\n", size);
		return S_OK;
	}

	STDMETHODIMP OutFile::Seek(Int64 offset, UInt32 seekOrigin, UInt64 *newPosition)
	{
		fprintf(stdout, "OutFile::Seek = %llu\n", offset);
		return S_OK;
	}

	STDMETHODIMP OutFile::SetSize(UInt64 newSize)
	{
		fprintf(stdout, "OutFile::SetSize = %llu\n", newSize);
		return S_OK;
	}

	OutFile::OutFile()
	{
		
	}

	OutFile::~OutFile()
	{
		
	}
	
}

