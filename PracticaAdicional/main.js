const $timer = document.querySelector("#timer")
setInterval(() => {
   const now = new Date()
   const hours = `${now.getHours()}`.padStart(2, "0")
   const minutes = `${now.getMinutes()}`.padStart(2, "0")
   const seconds = `${now.getSeconds()}`.padStart(2, "0")
   const milli = `${now.getMilliseconds()}`.padStart(3, "0")
   $timer.textContent = `${hours}:${minutes}:${seconds}:${milli}`
}, 1)
