/*
@filename: CEngine.h
*/
#ifndef CENGINE_H
#define CENGINE_H

#include <string>
#include <ctime>
#include <Mavgine2\Core\IEngine.h>
#include <Mavgine2\Core\Core.h>
#include "..\Plugin\PluginManager.h"
namespace Mavgine2
{
	class CEngine : public IEngine
	{
		friend void* ::GetEngine(const std::string &strVersion);

		public:
			virtual void Initialize(const std::string &strGameName, const unsigned int uiTickRate);
			virtual void EndGame();

			virtual int LoadPlugin(const std::string &strName);
			virtual bool UnloadPlugin(const int &id);

			virtual bool ShouldTick();
			virtual void Tick();

			virtual double GetEngineTime();
			virtual double GetRealTime();

			virtual EngineStatus GetStatus();
		private:
			CEngine();
			~CEngine();
			unsigned int m_uiTickRate;
			double m_dLastTick;

			clock_t m_engineStartClock;
			double m_dEngineTime;

			EngineStatus m_engineStatus;
	};
}

#endif