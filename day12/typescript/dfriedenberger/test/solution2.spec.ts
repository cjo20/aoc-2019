import { expect } from 'chai';
import { Space } from '../src/Space';
import { Moon } from '../src/Moon';

describe("Computer", () => {
    describe("run", () => {
        it("run simple program1", () => {
            
            let space : Space = new Space();
           
            space.add(new Moon({ x: -1, y: 0, z: 2 }));
            space.add(new Moon({ x: 2, y: -10, z: -7 }));
            space.add(new Moon({ x: 4, y: -8, z: 8 }));
            space.add(new Moon({ x: 3, y: 5, z: -1 }));

            for(let i = 1;i <= 2772;i++)
            {
                space.timeStep();
            }
            expect(space.moons[0].x[0]).to.equal(-1);

        });

       
    })
});