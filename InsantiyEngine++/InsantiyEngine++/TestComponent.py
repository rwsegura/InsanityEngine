import insanity_api

class TestComponent(ScriptComponent):
    def onCreate(self):
        print("Created")

    def onLoad(self):
        print("Loaded")

    def onUnload(self):
        print("Unloaded")

    def onUpdate(self):
        pass

    def onLateUpdate(self):
        pass

local_data = locals()
newComponent = TestComponent(local_data["object"], local_data["api"])