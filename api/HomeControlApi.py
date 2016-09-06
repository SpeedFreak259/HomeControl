from flask import Flask, jsonify
application = Flask(__name__)


@application.route("/api", methods=["GET"])
def hello():
    return "<h1 style='color:blue'>Hello World!</h1>"


@application.route("/api/lighting")
@application.route("/api/lighting/<zone>")
def zone_lighting(zone=None):
    if zone:
        return jsonify(zone=zone)
    else:
        return jsonify(zones=['playhouse', 'kitchen'])

if __name__ == "__main__":
    application.run(host="0.0.0.0")
