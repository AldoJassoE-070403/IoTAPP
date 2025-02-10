//Programacion necesaria con los indentificadores

/*
AEJE 1957302
DISEÑO DE SISTEMAS EMBEBIDOS
*/

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyAcQny59ysfpBkhQ3xGjyztIeDJcFo0G4o",
  authDomain: "iotapp-5608d.firebaseapp.com",
  databaseURL: "https://iotapp-5608d-default-rtdb.firebaseio.com",
  projectId: "iotapp-5608d",
  storageBucket: "iotapp-5608d.firebasestorage.app",
  messagingSenderId: "674127551078",
  appId: "1:674127551078:web:8b0f3b61c89682af1caba7"
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig);
var dbRef = firebase.database();
var GPIO = 0;

let dbGPIO = dbRef.ref("/ESP32IotAPP/GPIO");
dbGPIO.on('value', function(snapshot){
	console.log("El valor del GPIO es", snapshot.val());
	GPIO = snapshot.val();
	document.getElementById("GPIO_0_Id").innerHTML = "GPIO" + "" + "=" + GPIO; 
});
