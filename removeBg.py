import requests

api_key = 'jUFyLY5tqtbHNiKkJxyuNioM'

# URL for Remove.bg API endpoint
api_url = 'https://api.remove.bg/v1.0/removebg'

# Path to the image you want to process
image_path = 'BBL.jpg'

# Open the image file in binary mode
image_file = open(image_path, 'rb')

try:
    # Send a POST request to the Remove.bg API
    response = requests.post(
        api_url,
        files={'image_file': image_file},
        data={'size': 'auto'},  # 'auto' size keeps the original resolution
        headers={'X-Api-Key': api_key},
    )

    # Check if the request was successful (status code 200)
    if response.status_code == requests.codes.ok:
        # Save the processed image with background removed
        with open('output.png', 'wb') as out_file:
            out_file.write(response.content)
        print('Image saved successfully.')
    else:
        print(f'Error: {response.status_code}, {response.content}')

finally:
    # Close the image file
    image_file.close()
