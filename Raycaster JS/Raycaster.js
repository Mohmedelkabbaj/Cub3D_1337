const TILE_SIZE = 32;
const MAP_NUM_ROWS = 11;
const MAP_NUM_COLS = 15;

const WINDOW_WIDTH = MAP_NUM_COLS * TILE_SIZE;
const WINDOW_HEIGHT = MAP_NUM_ROWS * TILE_SIZE;

class Map {
    constructor() {
        this.grid = [
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
            [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
            [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        ];

    }
    render(){
        for (let i = 0; i < MAP_NUM_ROWS; i++) {
            for (let j = 0; j < MAP_NUM_COLS; j++) {
                let tileX = j * TILE_SIZE;
                let tileY = i * TILE_SIZE;
                let tileColor = this.grid[i][j] == 1 ? "#222" : "#fff";
                stroke("#222");
                fill(tileColor);
                rect(tileX, tileY, TILE_SIZE, TILE_SIZE);
            }
        }
    }

}

class Player {
    constructor(){
        this.x = WINDOW_WIDTH / 2;
        this.y = WINDOW_HEIGHT / 2;
        this.raduis = 3;
        this.turnDirection = 0;
        this.walkDirection = 0;
        this.rotationAngle = Math.PI / 2;
        this.moveSpeed = 2.0;
        this.rotaionSpeed = 2 * (Math.PI / 180 );
    }
    update(){
        this.rotationAngle += this.turnDirection * this.rotaionSpeed;

        var moveStep = this.walkDirection * this.moveSpeed;

        this.x = this.x + Math.cos(this.rotationAngle) * moveStep;
        this.y = this.y + Math.sin(this.rotationAngle) * moveStep;
   
    }
    render (){
        noStroke();
        fill("red");
        circle(this.x, this.y,this.raduis);
        stroke("red");
        line(
            this.x,
            this.y, 
            this.x + Math.cos(this.rotationAngle) * 30,
            this.y + Math.sin(this.rotationAngle) * 30
        )
    }
}

var grid = new Map();
var  player = new Player();

function keyPressed(){
    if(keyCode == UP_ARROW){
        player.walkDirection = +1;
    }else if(keyCode == DOWN_ARROW){
        player.walkDirection = -1;
    }else if(keyCode == RIGHT_ARROW){
        player.turnDirection = +1;
    }else if(keyCode == LEFT_ARROW){
        player.turnDirection = -1;
    }
}

function keyReleased()
{
    if(keyCode == UP_ARROW){
        player.walkDirection = 0;
    }else if(keyCode == DOWN_ARROW){
        player.walkDirection = 0;
    }else if(keyCode == RIGHT_ARROW){
        player.turnDirection = 0;
    }else if(keyCode == LEFT_ARROW){
        player.turnDirection = 0;
    }
}
function setup()
{
    // initialize all object
    createCanvas(WINDOW_WIDTH, WINDOW_HEIGHT);

}

function update()
{
    player.update();
}
function draw()
{
    // render all object FRAME BY FRAME
    update();
    grid.render();
    player.render();
}