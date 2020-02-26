#include <iostream>

#include <pp/PolyPlugin.hpp>

#include <AddIntent.hpp>

//------------------------------------------------------------------------------------------------------------------------------------------
class Plugin : public IPlugin
{
public:
	void init(std::shared_ptr<IntentRouter> router)
	{
		std::function<AddIntent::Result(AddIntent)> func = [this] (AddIntent intent) { return addIntentReceiver(std::move(intent)); };
		router->registerReceiver<AddIntent>(m_info, func);
	}

	void deinit(std::shared_ptr<IntentRouter> router)
	{

	}

	const PluginInfo& getPluginInfo() const
	{
		return m_info;
	}

private:
	AddIntent::Result addIntentReceiver(AddIntent intent)
	{
		return intent.a + intent.b;
	}

	PluginInfo m_info = { "Calculator", { 1, 0, 0} };
};

//------------------------------------------------------------------------------------------------------------------------------------------
POLY_PLUGIN_ENTRY()
{
	return new Plugin();
}