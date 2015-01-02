/*
 * Censure System - Naftan
 *
*/

#include "ScriptPCH.h"
#include "Channel.h"

class CensureSystem : public PlayerScript
{
public:
        CensureSystem() : PlayerScript("CensureSystem") {}

        void OnChat(Player* player, uint32 , uint32 lang, std::string& msg)
        {
                CheckMessage(player, msg, lang, NULL, NULL, NULL, NULL);
        }

        void OnChat(Player* player, uint32 , uint32 lang, std::string& msg, Player* receiver)
        {
                CheckMessage(player, msg, lang, receiver, NULL, NULL, NULL);
        }

        void OnChat(Player* player, uint32 , uint32 lang, std::string& msg, Group* group)
        {
                CheckMessage(player, msg, lang, NULL, group, NULL, NULL);
        }

        void OnChat(Player* player, uint32 , uint32 lang, std::string& msg, Guild* guild)
        {
                CheckMessage(player, msg, lang, NULL, NULL, guild, NULL);
        }

        void OnChat(Player* player, uint32 , uint32 lang, std::string& msg, Channel* channel)
        {
                CheckMessage(player, msg, lang, NULL, NULL, NULL, channel);
        }

void CheckMessage(Player* player, std::string& msg, uint32 lang, Player* , Group* , Guild* , Channel* channel)
{

    std::string lower = msg;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    uint8 cheksSize = 14; // Aquí se pondrá el número de checks que se enlistan.
    std::string checks[14]; // Aquí se pondrá el número de checks que se enlistan.
    // Checks
    checks[0] ="http://";
    checks[1] ="https://";
    checks[2] =".com";
    checks[3] =".www";
    checks[4] =".net";
    checks[5] =".org";
    checks[6] =".es";
    checks[7] ="www.";
    checks[8] ="wow-";
    checks[9] ="-wow";
    checks[10] ="zorr";
    checks[11] ="put";
    checks[12] ="verg";
    checks[13] ="mierd";

    for (int i = 0; i < cheksSize; ++i)
        if (lower.find(checks[i]) != std::string::npos)
        {
            msg = " ";
            ChatHandler(player->GetSession()).PSendSysMessage("""\xc2\xa1""La publicidad y el comportamiento vulgar no est""\xC3\xA1""n permitidos!, WoWRean.");
            return;
        }

}
};

void AddSC_CensureSystem()
{
    new CensureSystem();
}
