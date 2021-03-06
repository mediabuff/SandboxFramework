#pragma once

#include "XElement.h"

namespace XML
{
	struct XDocument
	{
		XElement* Root;
		std::string Encoding;
		Collections::ArrayList<std::string> Errors;

#ifdef VISUAL_SCHOOL
		XDocument() {}
#else
		XDocument() = default;
#endif
		~XDocument();

		inline bool Success() { return Errors.GetCount() == 0; }
		
		std::string ToString();
		void Save(std::string path);
		static XDocument* Load(std::string path);
	};
}