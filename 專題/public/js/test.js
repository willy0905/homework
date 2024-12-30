const wakeLockCheckbox = document.querySelector('#wakeLockCheckbox');
const reaquireCheckbox = document.querySelector('#reacquireCheckbox');

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
  
  const handleVisibilityChange = () => {    
    if (wakeLock !== null && document.visibilityState === 'visible') {
      wakeLock = requestWakeLock();
    }
  };    
  
  reaquireCheckbox.addEventListener('change', () => {
    if (reaquireCheckbox.checked) {
      document.addEventListener('visibilitychange', handleVisibilityChange);
      document.addEventListener('fullscreenchange', handleVisibilityChange);
    } else {
      document.removeEventListener('visibilitychange', handleVisibilityChange);
      document.removeEventListener('fullscreenchange', handleVisibilityChange);      
    }
  });  
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
  
  const handleVisibilityChange = () => {    
    if (wakeLock !== null && document.visibilityState === 'visible') {
      requestWakeLock();
    }
  };    
  
  reaquireCheckbox.addEventListener('change', () => {
    if (reaquireCheckbox.checked) {
      document.addEventListener('visibilitychange', handleVisibilityChange);
      document.addEventListener('fullscreenchange', handleVisibilityChange);
    } else {
      document.removeEventListener('visibilitychange', handleVisibilityChange);
      document.removeEventListener('fullscreenchange', handleVisibilityChange);      
    }
  });  
} 
