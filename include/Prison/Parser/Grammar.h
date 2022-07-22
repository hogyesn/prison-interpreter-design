#ifndef PRISON_PARSER_GRAMMAR
#define PRISON_PARSER_GRAMMAR

#include <map>
#include <iostream>

namespace Prison { namespace Parser {

class Grammar {
	public:
		Grammar() {
			m_tokens["nl"] = "\r?\n";
			m_tokens["utf8bom"] = "\xef?\xbb?\xbf?";

			m_tokens["if"] = "if";
			m_tokens["else"] = "else";
			m_tokens["for"] = "for";
			m_tokens["return"] = "return";

			m_tokens["id"] = "[a-zA-Z][a-zA-Z_0-9]*";

			m_tokens["int"] = "[0-9]+";
			m_tokens["float"] = "([0-9]+([.][0-9]*)?|[.][0-9]+)";
			m_tokens["false"] = "false";
			m_tokens["true"] = "true";
			m_tokens["string"] = "\".*\"";

			m_tokens["plus"] = "\\+";
			m_tokens["semicolon"] = "\\;";
			m_tokens["ro_br_l"] = "\\(";
			m_tokens["ro_br_r"] = "\\)";
			m_tokens["sq_br_l"] = "\\[";
			m_tokens["sq_br_r"] = "\\]";
			m_tokens["cu_br_l"] = "\\{";
			m_tokens["cu_br_r"] = "\\}";
			m_tokens["assign"] = "=";
			m_tokens["equals"] = "==";
			m_tokens["not_equals"] = "!=";
		}

		~Grammar() {
		}

		void each(std::function<bool(const char *, const char*)> callback) {
			std::map<const char *, const char *>::iterator iterator;

			for	(iterator = m_tokens.begin(); iterator != m_tokens.end(); iterator++) {
				if(!callback(iterator->first, iterator->second)) {
					break;
				}
			}
		}


	private:
		std::map<const char *, const char *> m_tokens;
};

}};// namespace Prison::Parser

#endif
