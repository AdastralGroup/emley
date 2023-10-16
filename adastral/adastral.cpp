#include <iostream>

#include <kachemak/kachemak.hpp>

using namespace std;

int main()
{
	filesystem::path sourcemodPath = Utility::GetSteamSourcemodPath();
	if (sourcemodPath.empty())
	{
		printf("Error: Steam installation not found");
		return 1;
	}

	Kachemak kachemak = Kachemak(sourcemodPath, "tf2classic");
	printf("Latest version: %s - Installed version: %s\n", kachemak.GetLatestVersion().value().szVersion.c_str(), kachemak.GetInstalledVersion().c_str());
	
	kachemak.Update();
	return 0;
}
