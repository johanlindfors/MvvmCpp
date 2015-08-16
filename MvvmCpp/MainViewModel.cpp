#include "pch.h" 
#include "MainViewModel.h" 
#include "DelegateCommand.h" 
#include <ppltasks.h>
#include <agents.h>

using namespace MvvmCpp;
using namespace Common;
using namespace Platform;
using namespace std;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;

using namespace concurrency;
using namespace std::chrono;
using namespace std::literals;

MainViewModel::MainViewModel()
{
	m_ButtonClickCommand = ref new DelegateCommand(
		ref new ExecuteDelegate(this, &MainViewModel::OnButtonClicked),
		ref new CanExecuteDelegate(this, &MainViewModel::IsValid));
}

MainViewModel::~MainViewModel()
{
}

String^ MainViewModel::Title::get()
{
	return m_title;
}

void MainViewModel::Title::set(String^ value)
{
	if (m_title != value)
	{
		m_title = value;
		OnPropertyChanged("Title");
	}
}

ICommand^ MainViewModel::ButtonClickCommand::get()
{
	return m_ButtonClickCommand;
}

void MainViewModel::OnButtonClicked(Object^ parameter)
{
	try {
		IsBusy = true;

		create_task([=](){
			try {
				this_thread::sleep_for(seconds(2));
				IsBusy = false;
			}
			catch (Exception^ innerException) {
				auto ex = innerException;
				throw ex;
			}
		}, task_continuation_context::use_default())
			.then([=](task<void> t) {
			try {
				t.get();
			}
			catch (Exception^ finalException) {
				auto ex = finalException;
			}
			IsBusy = false;
		}, task_continuation_context::use_current());
	}
	catch (Exception^ outerException) {

	}
}

bool MainViewModel::IsValid(Object^ parameter)
{
	return !IsBusy;
}