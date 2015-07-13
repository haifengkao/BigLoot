/*  LOOT

    A load order optimisation tool for Oblivion, Skyrim, Fallout 3 and
    Fallout: New Vegas.

    Copyright (C) 2012-2015    WrinklyNinja

    This file is part of LOOT.

    LOOT is free software: you can redistribute
    it and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    LOOT is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with LOOT.  If not, see
    <http://www.gnu.org/licenses/>.
    */

#ifndef __LOOT_MASTERLIST__
#define __LOOT_MASTERLIST__

#include "metadata_list.h"

#include <string>

#include <boost/filesystem.hpp>

namespace loot {
    class Game;

    class Masterlist : public MetadataList {
    public:

        bool Load(Game& game, const unsigned int language);  //Handles update with load fallback.

        bool Update(const boost::filesystem::path& path,
                    const std::string& repoURL,
                    const std::string& repoBranch);

        std::string GetRevision(const boost::filesystem::path& path, bool shortID);
        std::string GetDate(const boost::filesystem::path& path);

    private:
        bool Update(const Game& game);
        void GetGitInfo(const boost::filesystem::path& path, bool shortID);

        std::string revision;
        std::string date;
    };
}

#endif