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


#ifndef __LZMASDKOBJCEXTRACTCALLBACK_H__
#define __LZMASDKOBJCEXTRACTCALLBACK_H__

#include "LzmaAppleCommon.h"
#include "LzmaSDKObjCTypes.h"

#include "../lzma/CPP/7zip/Archive/IArchive.h"
#include "../lzma/CPP/7zip/IPassword.h"
#include "../lzma/CPP/7zip/ICoder.h"
#include "../lzma/CPP/Common/MyCom.h"
#include "../lzma/CPP/Common/MyString.h"
#include "../lzma/CPP/7zip/Common/FileStreams.h"

#include "LzmaSDKObjCOutFile.h"
#include "LzmaSDKObjCICoder.h"

#ifndef SAFE_FREE
#define SAFE_FREE(m) if(m){free(m);m=NULL;}
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(o) if(o){delete o;o=NULL;}
#endif

namespace LzmaSDKObjC
{
	class ExtractCallback :
		public IArchiveExtractCallback,
		public IArchiveExtractCallbackMessage,
		public ICryptoGetTextPassword,
		public ICryptoGetTextPassword2,
		public ICompressProgressInfo,
		public CMyUnknownImp
	{
	private:
		LzmaSDKObjC::OutFile * _outFileStreamSpec;
		LzmaSDKObjC::ICoder * _coder;
		CMyComPtr<ISequentialOutStream> _outFileStream;

		uint64_t _total;

		UString _password;

	public:
		MY_UNKNOWN_IMP4(IArchiveExtractCallbackMessage, ICryptoGetTextPassword, ICryptoGetTextPassword2, ICompressProgressInfo)

		INTERFACE_IArchiveExtractCallback(;)
		INTERFACE_IArchiveExtractCallbackMessage(;)

		STDMETHOD(SetRatioInfo)(const UInt64 *inSize, const UInt64 *outSize);

		// ICryptoGetTextPassword
		STDMETHOD(CryptoGetTextPassword)(BSTR *password);

		// ICryptoGetTextPassword2
		STDMETHOD(CryptoGetTextPassword2)(Int32 *passwordIsDefined, BSTR *password);

		void setCoder(LzmaSDKObjC::ICoder * coder) { _coder = coder; }

		ExtractCallback();
		virtual ~ExtractCallback();
	};
	
}

#endif 