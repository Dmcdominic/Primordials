/* demo_menu.cpp source - f19 base6 - https://github.com/15-466/15-466-f19-base6 */

#include "demo_menu.hpp"
#include "Load.hpp"
#include "data_path.hpp"

#include "PlayMode.hpp"

//Load< SpriteAtlas > trade_font_atlas(LoadTagDefault, []() -> SpriteAtlas const* {
//	return new SpriteAtlas(data_path("trade-font"));
//});

std::shared_ptr< MenuMode > demo_menu;

Load< void > load_demo_menu(LoadTagDefault, []() {
	std::vector< MenuMode::Item > items;
	items.emplace_back("[[ DEMO MENU ]]");
	items.emplace_back("play");
	items.back().on_select = [](MenuMode::Item const&) {
		Mode::set_current(std::make_shared< PlayMode >());
	};
	items.emplace_back("example item 2 (also starts PlayMode). This'll be super long so that we can see what happens");
	items.back().on_select = [](MenuMode::Item const&) {
		Mode::set_current(std::make_shared< PlayMode >());
	};
	/*items.emplace_back("lighting - forward");
	items.back().on_select = [](MenuMode::Item const&) {
		Mode::set_current(std::make_shared< DemoLightingForwardMode >());
	};
	items.emplace_back("lighting - deferred");
	items.back().on_select = [](MenuMode::Item const&) {
		Mode::set_current(std::make_shared< DemoLightingDeferredMode >());
	};*/


	demo_menu = std::make_shared< MenuMode >(items);
	demo_menu->selected = 1;
	demo_menu->view_min = glm::vec2(0.0f, 0.0f);
	demo_menu->view_max = glm::vec2(320.0f, 200.0f);
});