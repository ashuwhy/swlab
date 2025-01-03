    //Scripted by DDPRASAD
    document.addEventListener('DOMContentLoaded', function() {
        // Create a div to hold the clocks
        var clockDiv = document.createElement('div');
        clockDiv.id = 'nav-clocks';
        //clockDiv.style.color = 'white';
        //clockDiv.style.marginTop = '2px';
        //clockDiv.style.fontSize = '14px';
        //clockDiv.style.fontWeight = 'bold';
        //clockDiv.style.padding = '2px';

        // Create divs for server time and client time
        var serverClockDiv = document.createElement('div');
        serverClockDiv.id = 'server-clock';
        var clientClockDiv = document.createElement('div');
        clientClockDiv.id = 'client-clock';

        // Append clocks to the main clock div
        clockDiv.appendChild(serverClockDiv);
        clockDiv.appendChild(clientClockDiv);

        // Insert the clock div into the navigation bar
        // var navbar = document.querySelector('.usermenu'); // Adjust this selector based on your inspection
        // if (navbar) {
        //    navbar.appendChild(clockDiv);
	// Insert the clock div before the logout button
    	var domElement = document.querySelector('.usermenu-container'); // Adjust this selector based on your inspection
    	if (domElement) {
        	domElement.parentNode.insertBefore(clockDiv, domElement);

            let serverTime;

            function updateClientClock() {
                var now = new Date();
                var weekdays = ['Sun ', 'Mon ', 'Tue ', 'Wed ', 'Thu ', 'Fri ', 'Sat '];
                var day = weekdays[now.getDay()];
                updateClock(now, clientClockDiv, '<span class=timeInfo>Your Time: </span>', day);
            }

            function updateServerClock() {
                serverTime.setSeconds(serverTime.getSeconds() + 1);
                var weekdays = ['Sun ', 'Mon ', 'Tue ', 'Wed ', 'Thu ', 'Fri ', 'Sat '];
                var day = weekdays[serverTime.getDay()];
                updateClock(serverTime, serverClockDiv, '<span class=timeInfo>Server Time: </span>', day);
            }

            function updateClock(time, element, label, day = '') {
                var hours = time.getHours();
                var minutes = time.getMinutes();
                var seconds = time.getSeconds();
                var ampm = hours >= 12 ? 'PM' : 'AM';

                // Convert hours from 24-hour to 12-hour format
                hours = hours % 12;
                hours = hours ? hours : 12; // the hour '0' should be '12'
                minutes = minutes < 10 ? '0' + minutes : minutes;
                seconds = seconds < 10 ? '0' + seconds : seconds;

                var timeString = label + (day ? day + ' ' : '') + hours + ':' + minutes + ':' + seconds + ' ' + ampm;
                element.innerHTML  = timeString;
            }

            // Fetch the server time
            function fetchServerTime() {
                fetch('/moodle/lib/ajax/serverTime.php') // Adjust the path as needed
                    .then(response => response.json())
                    .then(data => {
                        serverTime = new Date(data.serverTime); // Assume server returns time in ISO format
                        updateServerClock();
                    })
                    .catch(error => console.error('Error fetching server time:', error));
            }

            // Initial call to fetch server time and update client clock
            fetchServerTime();
            updateClientClock();

            // Update the clocks every second
            setInterval(updateClientClock, 1000);
            setInterval(updateServerClock, 1000); // Update server clock every second locally
          
            // Fetch server time every 2.5 minutes (150000 milliseconds)
            setInterval(fetchServerTime, 150000);
        }
    });
