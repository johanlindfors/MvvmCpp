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

// Creates a task that completes after the specified delay.
task<void> delay(unsigned int timeout)
{
	// A task completion event that is set when a timer fires .
	task_completion_event<void> tce;

	// Create a non-repeating timer.
	auto fire_once = new timer<int>(timeout, 0, nullptr, false);
	// Create a call object that sets the completion event after the timer fires.
	auto callback = new call<int>([tce](int)
	{
		tce.set();
	});

	// Connect the timer to the callback and start the timer.
	fire_once->link_target(callback);
	fire_once->start();

	// Create a task that completes after the completion event is set.
	task<void> event_set(tce);

	// Create a continuation task that cleans up resources and
	// return that continuation task.
	return event_set.then([callback, fire_once]()
	{
		delete callback;
		delete fire_once;
	});
}

void MainViewModel::OnButtonClicked(Object^ parameter)
{
	try {
		IsBusy = true;

		delay(2500).then([=]() {
			try {
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
	catch (Exception^ exception) {

	}
}

bool MainViewModel::IsValid(Object^ parameter)
{
	return !IsBusy;
}