#pragma once

#include "MainViewModel.h" // Required by generated header

namespace Common
{
    class Repository;
    [Windows::UI::Xaml::Data::Bindable]
    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class ViewModelLocator sealed
    {
    public:
        ViewModelLocator();

		property MvvmCpp::IMainViewModel^ MainViewVM { MvvmCpp::IMainViewModel^ get(); }
        
    private:
		MvvmCpp::IMainViewModel^ mMainViewVM;
    };
}