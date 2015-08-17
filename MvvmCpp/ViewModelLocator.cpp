#include "pch.h"
#include "ViewModelLocator.h"

using namespace MvvmCpp;
using namespace Common;

ViewModelLocator::ViewModelLocator()
{
}

IMainViewModel^ ViewModelLocator::MainViewVM::get()
{
	if (mMainViewVM == nullptr) {
		mMainViewVM = ref new MainViewModel();
	}
	return mMainViewVM;
}