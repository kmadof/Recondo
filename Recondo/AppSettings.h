#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <string>

class AppSettings
{
	public :
		static AppSettings& GetInstrance() {
			static AppSettings instance;
			return instance;
		}

		std::string GetCoursesPath() const { return _coursesPath; }
		void SetCoursesPath(std::string coursesPath) { _coursesPath = coursesPath; }

	private:
		AppSettings();
		AppSettings(const AppSettings&);

		std::string _coursesPath;
};

#endif