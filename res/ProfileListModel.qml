import QtQuick

Item {
    property string jsonPath

    property ListModel categoryListModel: ListModel {}

    property var categoryModels: {

    }
    function saveToJson() {
        var jsonObject = {}

        for (var i = 0; i < categoryListModel.count; i++) {

            var category = categoryListModel.get(i).category
            var categoryModel = categoryModels[category]

            jsonObject[category] = {}
            for (var j = 0; j < categoryModel.count; j++) {
                var listElement = categoryModel.get(j)
                jsonObject[category][listElement.key] = listElement.value
            }
        }

        mainWindowViewModel.saveToJson(jsonObject, jsonPath)
    }

    function loadFromJson() {
        var jsonObject = mainWindowViewModel.loadFromJson(jsonPath)

        for (var i = 0; i < categoryListModel.count; i++) {

            var category = categoryListModel.get(i).category
            var categoryModel = categoryModels[category]

            for (var j = 0; j < categoryModel.count; j++) {
                var listElement = categoryModel.get(j)
                listElement.value = jsonObject[category][listElement.key]
            }
        }
    }
}
