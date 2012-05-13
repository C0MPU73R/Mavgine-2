#ifndef CENGINE_H
#define CENGINE_H

#include <string>
#include "IEngine.h"
#include "..\Core.h"

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

		private:
			CEngine();
			~CEngine();
			unsigned int m_uiTickRate;
	};
}

#endif