async function register ({ registerHook, registerSetting, settingsManager, storageManager, AleftubeHelpers }) {
  registerHook({
    target: 'filter:api.videos.list.params',
    handler: obj => addToCount(obj)
  })
}

async function unregister () {
  return
}

module.exports = {
  register,
  unregister
}

// ############################################################################

function addToCount (obj) {
  return Object.assign({}, obj, { count: obj.count + 1 })
}


