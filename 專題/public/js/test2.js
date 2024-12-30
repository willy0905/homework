var clickArea = document.getElementById('clickArea');
const wakeLockCheckbox = document.querySelector('#wakeLockCheckbox');
wakeLockCheckbox.checked = true;

clickArea.addEventListener('click', function(event) {
  console.log('點擊事件觸發了！');
  if ('WakeLock' in window && 'request' in window.WakeLock) {  
    let wakeLock = null;
    const requestWakeLock = () => {
      const controller = new AbortController();
      const signal = controller.signal;
      window.WakeLock.request('screen', {signal})
        .catch((e) => {      
        if (e.name === 'AbortError') {
          wakeLockCheckbox.checked = false;
          console.log('Wake Lock was aborted');
        } else {
          console.error("error");
        }
      });
      wakeLockCheckbox.checked = true;
      console.log('Wake Lock is active');
      return controller;
    };
    wakeLockCheckbox.addEventListener('change', () => {
      if (wakeLockCheckbox.checked) {
        wakeLock = requestWakeLock();
      } else {
        wakeLock.abort();
        wakeLock = null;
      }
    });
    //alert(wakeLockCheckbox.checked);
  } else if ('wakeLock' in navigator && 'request' in navigator.wakeLock) {  
    let wakeLock = null;
    const requestWakeLock = async () => {
      try {
        wakeLock = await navigator.wakeLock.request('screen');
        wakeLock.addEventListener('release', (e) => {
          console.log(e);
          wakeLockCheckbox.checked = false;
          console.log('Wake Lock was released');                    
        });
        wakeLockCheckbox.checked = true;
        console.log('Wake Lock is active');      
      } catch (e) {      
        wakeLockCheckbox.checked = false;
        console.error("error");
      } 
    };
    wakeLockCheckbox.addEventListener('change', () => {
      if (wakeLockCheckbox.checked) {
        requestWakeLock();
      } else {
        wakeLock.release();
        wakeLock = null;
      }
    });  
    //alert(wakeLockCheckbox.checked);
    if (wakeLockCheckbox.checked) {
      wakeLockCheckbox.dispatchEvent(new Event('change'));
      console.log("123");
    } 
  }
  
});









 
