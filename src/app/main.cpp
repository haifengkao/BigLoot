#include "loot/api.h"
#include <stdio.h>

using namespace loot;
using namespace std;

typedef std::shared_ptr<GameInterface> GameHandle;
int main(int argc, char const *argv[]) {
    
    std::vector<std::string> sortedPlugins;
    try {
        string testFolder = "/Volumes/MacintoshHD-資料/Dropbox/Project/BigLoot/LOOT-tést";
        string gameFolder = testFolder + "/game";
        string localFolder = testFolder + "/local";
        GameHandle game = CreateGameHandle(GameType::tes5, gameFolder, localFolder);
        //game->IdentifyMainMasterFile
        
        try {
            game->LoadCurrentLoadOrderState();
          } catch (std::exception& e) {
              /*
            if (logger) {
              logger->error("Failed to load current load order. Details: {}", e.what());
            }
            AppendMessage(PlainTextMessage(
                MessageType::error,
                boost::locale::translate("Failed to load the current load order, "
                                         "information displayed may be incorrect.")
                    .str()));
               */
          }
        
        
          try {
            // Clear any existing game-specific messages, as these only relate to
            // state that has been changed by sorting.
            //ClearMessages();

            auto currentLoadOrder = game->GetLoadOrder();

            sortedPlugins = game->SortPlugins(currentLoadOrder);

            //AppendMessages(CheckForRemovedPlugins(currentLoadOrder, sortedPlugins));

            //IncrementLoadOrderSortCount();
          } catch (CyclicInteractionError& e) {
              /*
            if (logger) {
              logger->error("Failed to sort plugins. Details: {}", e.what());
            }
            AppendMessage(Message(
                MessageType::error,
                (boost::format(boost::locale::translate(
                     "Cyclic interaction detected between \"%1%\" and \"%2%\": %3%")) %
                 EscapeMarkdownSpecialChars(e.GetCycle().front().GetName()) %
                 EscapeMarkdownSpecialChars(e.GetCycle().back().GetName()) %
                 DescribeCycle(e.GetCycle()))
                    .str()));
               */
            sortedPlugins.clear();
          } catch (UndefinedGroupError& e) {
              /*
            if (logger) {
              logger->error("Failed to sort plugins. Details: {}", e.what());
            }
            AppendMessage(PlainTextMessage(MessageType::error,
                                           (boost::format(boost::locale::translate(
                                                "The group \"%1%\" does not exist.")) %
                                            e.GetGroupName())
                                               .str()));*/
            sortedPlugins.clear();
          } catch (std::exception& e) {
              /*
            if (logger) {
              logger->error("Failed to sort plugins. Details: {}", e.what());
            }
            sortedPlugins.clear();*/
          }


    }
    catch (...) {
        printf("some error");
        //SetLoggingCallback([](LogLevel, const char *) {});
    }

    printf("success %lu", sortedPlugins.size());
    return 0;
}
